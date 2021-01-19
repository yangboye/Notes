#pragma once
// File name: my_any.h
// Brief		: 实现一个类似于std::any的类
#include <iostream>
#include <memory>
#include <typeindex>

class MyAny {
public:
	MyAny()
		: type_idx_(std::type_index(typeid(void))) {}

	MyAny(const MyAny& rhs)
		: ptr_(rhs.Clone()),
			type_idx_(rhs.type_idx_) {}

	MyAny(MyAny&& rhs)
		: ptr_(std::move(rhs.ptr_)),
			type_idx_(rhs.type_idx_) {}

	// 创建智能指针时，对于一般的类型，通过std::decay来移除引用和cv符没从而获取原始类型
	template<typename U, class=
		typename std::enable_if<!std::is_same<typename std::decay<U>::type, MyAny>::value, U>::type>
	MyAny(U&& value)
		: ptr_(new Derived<typename std::decay<U>::type>(std::forward<U>(value))),
		  type_idx_(std::type_index(typeid(typename std::decay<U>::type))) {}

	inline bool IsNull() const {
		return !bool(ptr_);
	}

	template<class U> 
	inline bool Is() const {
		return type_idx_ == std::type_index(typeid(U));
	}

	// 将MyAny 类型转换为实际的类型
	template<class U>
	U& AnyCast() {
		if (!Is<U>()) {
			std::cout << "Cannot cast " << typeid(U).name() << " to " << type_idx_.name() << std::endl;
			throw std::bad_cast();
		}

		auto derived = dynamic_cast<Derived<U>*>(ptr_.get());
		return derived->value_;
	}

	MyAny& operator=(const MyAny& rhs) {
		if (ptr_ == rhs.ptr_) {
			return *this;
		}

		ptr_ = rhs.Clone();
		type_idx_ = rhs.type_idx_;
		return *this;
	}

private:
	class Base;
	using base_ptr = std::unique_ptr<Base>;

	class Base {	// 基类
	public:
		virtual ~Base() {}
		virtual base_ptr Clone() const = 0;	// 纯虚函数
	};

	template<typename T>
	class Derived : public Base {
	public:
		template<typename U>
		Derived(U&& value)
			: value_(std::forward<U>(value)) {}

		base_ptr Clone() const override {
			return base_ptr(new Derived<T>(value_));
		}

	public:
		T value_;
	};

	base_ptr Clone() const {
		if (ptr_ != nullptr) {
			return ptr_->Clone();
		}
		return nullptr;
	}

	base_ptr ptr_;
	std::type_index type_idx_;
};