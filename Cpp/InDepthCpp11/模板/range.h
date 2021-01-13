#pragma once
// 实现一个Range(start, end, step), [start, end)，步长setp

namespace detail_range {

// 迭代器
template <typename T>
class Iterator {
public:
	using value_type = T;
	using size_type = size_t;

public:
	Iterator(size_type cur_start, value_type begin_val, value_type step_val);
	value_type operator*() const;
	bool operator!=(const Iterator& rhs) const;
	Iterator& operator++();

private:
	size_type				 cursor_;	// 开始的迭代次数
	const value_type step_;		// 迭代步长
	value_type			 value_;	// 初始值
};


class Range
{
public:
	Range();
	~Range();
};


}	// namespace detail_range

