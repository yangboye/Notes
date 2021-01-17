#pragma once

#define HAS_MEMBER(member) \ 
template<typename T, typename... Args> \
struct has_member##member { \
private: \
	template<typename U> \
	static auto Chekc(int) -> decltype(std::declval<U>().member(std::declval<Args>()...), std::true_type());	\
	template<typename U> \
	static std::false_type Check(...);	\
public: \
	enum {value = std::is_name<decltype>(Check<T>(0)), std::true_type::value}; \
};\
