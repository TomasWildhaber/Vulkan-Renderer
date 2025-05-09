#pragma once
#include "Core/Core.h"

template<typename T>
class WeakRef
{
public:
	WeakRef() noexcept = default;
	WeakRef(const Ref<T>& ref) noexcept : m_Ptr(ref.GetPtr()), m_RefCount((uint32_t*)&ref.GetRefCount()) {}
	~WeakRef() noexcept = default;

	inline operator bool() const noexcept { return IsValid(); }
	inline operator T* () const noexcept { return m_Ptr; }
	inline T* operator->() const noexcept { return m_Ptr; }
	inline T& operator*() const noexcept { return *m_Ptr; }

	inline T* GetPtr() const noexcept { return m_Ptr; }
	inline T& Get() const noexcept { return *m_Ptr; }

	inline const bool IsValid() const noexcept { return m_RefCount && *m_RefCount != UNDEFINED_PTR; }
	inline Ref<T> Lock() const noexcept { return IsValid() ? Ref<T>(m_Ptr, m_RefCount) : Ref<T>(nullptr); }
private:
	T* m_Ptr = nullptr;
	uint32_t* m_RefCount = 0;
};