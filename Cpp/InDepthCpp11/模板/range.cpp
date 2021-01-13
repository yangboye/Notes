#include "range.h"

template <typename T>
detail_range::Iterator<T>::Iterator(size_type cur_start, value_type begin_val, value_type step_val)
	: cursor_(cur_start), step_(step_val), value_(begin_val) 
{
	value_ += (step_ * cursor_);
}

template<typename T>
detail_range::Iterator<T>::value_type detail_range::Iterator<T>::operator*() const {
	return value_;
}

template<typename T>
bool detail_range::Iterator<T>::operator!=(const Iterator & rhs) const {
	return (cursor_ != rhs.cursor_);
}

template<typename T>
detail_range::Iterator<T>& detail_range::Iterator<T>::operator ++() {
	value_ += step_;
	++cursor_;
	return (*this);
}

detail_range::Range::Range()
{
}


detail_range::Range::~Range()
{
}
