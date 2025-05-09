#pragma once

#ifdef DEBUG_CONFIG
	inline uint32_t AllocatedScopeRefCount = 0;

	#define ALLOCATED_SCOPEREF_COUNT AllocatedScopeRefCount
#else
	#define ALLOCATED_SCOPEREF_COUNT 0
#endif

template<typename T>
class ScopeRef
{
public:
	ScopeRef() noexcept = default;
	ScopeRef(T* ptr) noexcept : m_Ptr(ptr)
	{
#ifdef DEBUG_CONFIG
		AllocatedScopeRefCount++;
#endif
	}

	~ScopeRef() noexcept { Reset(); }

	ScopeRef(const ScopeRef&) = delete;

	template<typename... Args>
	static ScopeRef<T> Create(Args&&... args) noexcept { return new T(std::forward<Args>(args)...); }

	template<typename T2, typename = std::enable_if_t<std::is_convertible_v<T*, T2*>>>
	inline operator ScopeRef<T2>() && noexcept { return this->Release(); }

	inline operator bool() const noexcept { return m_Ptr; }
	inline operator T* () const noexcept { return m_Ptr; }
	inline T* operator->() const noexcept { return m_Ptr; }
	inline T& operator*() const noexcept { return *m_Ptr; }

	inline T* GetPtr() const noexcept { return m_Ptr; }
	inline T& Get() const noexcept { return *m_Ptr; }

	inline ScopeRef& operator=(const ScopeRef&) = delete;

	inline ScopeRef& operator=(ScopeRef&& other) noexcept
	{
		if (this != &other)
		{
			delete m_Ptr;
			m_Ptr = other.m_Ptr;
			other.m_Ptr = nullptr;
		}

		return *this;
	}

	inline void Reset(T* ptr = nullptr) noexcept
	{
		delete m_Ptr;
		m_Ptr = ptr;

#ifdef DEBUG_CONFIG
		if (!ptr)
			AllocatedScopeRefCount--;
#endif
	}

	inline T* Release()
	{
		T* ptr = m_Ptr;
		m_Ptr = nullptr;
		return ptr;
	}
private:
	T* m_Ptr = nullptr;
};