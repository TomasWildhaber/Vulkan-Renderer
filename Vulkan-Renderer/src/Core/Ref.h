#pragma once

#ifdef DEBUG_CONFIG
	inline uint32_t AllocatedRefCount = 0;

	#define ALLOCATED_REF_COUNT AllocatedRefCount
#else
	#define ALLOCATED_REF_COUNT 0
#endif

template<typename T>
class Ref
{
public:
	Ref(T* ptr = nullptr) : m_Ptr(ptr), m_RefCount(new uint32_t(1))
	{
#ifdef DEBUG_CONFIG
		AllocatedRefCount++;
#endif
	}

	Ref(T* _ptr, uint32_t* _refs) noexcept : m_Ptr(_ptr), m_RefCount(_refs) { ++(*m_RefCount); }
	Ref(const Ref& other) noexcept : m_Ptr(other.m_Ptr), m_RefCount(other.m_RefCount) { ++(*m_RefCount); }

	Ref(Ref&& other) noexcept : m_Ptr(other.m_Ptr), m_RefCount(other.m_RefCount)
	{
		other.m_Ptr = nullptr;
		other.m_RefCount = nullptr;
	}

	~Ref() noexcept { Reset(); }

	template<typename... Args>
	static Ref<T> Create(Args&&... args) noexcept { return new T(std::forward<Args>(args)...); }

	inline operator bool() const noexcept { return m_Ptr; }
	inline operator T* () const noexcept { return m_Ptr; }
	inline T* operator->() const noexcept { return m_Ptr; }
	inline T& operator*() const noexcept { return *m_Ptr; }

	inline T* GetPtr() const noexcept { return m_Ptr; }
	inline T& Get() const noexcept { return *m_Ptr; }

	template<typename T2, typename = std::enable_if_t<std::is_convertible_v<T*, T2*>>>
	inline operator Ref<T2>() noexcept { return Ref<T2>(m_Ptr, m_RefCount); }

	template<typename T2, typename = std::enable_if_t<std::is_convertible_v<T*, T2*>>>
	inline Ref<T2> As() const noexcept { return Ref<T2>(m_Ptr, m_RefCount); }

	inline const uint32_t& GetRefCount() const noexcept { return *m_RefCount; }

	inline bool operator==(const Ref& other) const noexcept { return m_Ptr == other.m_Ptr; }

	inline Ref& operator=(const Ref& other) noexcept
	{
		if (this != &other)
		{
			Reset();
			m_Ptr = other.m_Ptr;
			m_RefCount = other.m_RefCount;
			++(*m_RefCount);
		}

		return *this;
	}

	inline Ref& operator=(Ref&& other) noexcept
	{
		if (this != &other)
		{
			Reset();
			m_Ptr = other.m_Ptr;
			m_RefCount = other.m_RefCount;
			other.m_Ptr = nullptr;
			other.m_RefCount = nullptr;
		}

		return *this;
	}

	inline void Reset() noexcept
	{
		if (m_RefCount && --(*m_RefCount) == 0)
		{
			delete m_Ptr;
			delete m_RefCount;
			m_Ptr = nullptr;
			m_RefCount = nullptr;

#ifdef DEBUG_CONFIG
			AllocatedRefCount--;
#endif
		}
	}
private:
	T* m_Ptr = nullptr;
	uint32_t* m_RefCount;
};