#pragma once

class NonCopyable {
protected:
	NonCopyable() = default;
	~NonCopyable() = default;
	NonCopyable(const NonCopyable&) = delete;	// 禁用复制构造函数
	NonCopyable& operator=(const NonCopyable&) = delete;	// 禁用赋值构造函数
};