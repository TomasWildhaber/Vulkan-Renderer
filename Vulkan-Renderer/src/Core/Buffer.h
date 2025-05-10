#pragma once

namespace VulkanRenderer
{
	class Buffer
	{
	public:
		Buffer() noexcept = default;
		Buffer(uint32_t size) noexcept;
		~Buffer();

		void Allocate(uint32_t size) noexcept;
		void Release() noexcept;

		void WriteZeros();
		void Write(const void* data, uint32_t size);

		template<typename T>
		inline T* GetDataAs() noexcept { return (T*)m_Data; }
		inline char* GetData() noexcept { return (char*)m_Data; }

		inline const uint32_t GetSize() const noexcept { return m_Size; }
		inline const bool IsEmpty() const noexcept { return !*m_Data; }

		operator bool() const noexcept { return (bool)m_Data; }
	private:
		uint8_t* m_Data = nullptr;
		uint32_t m_Size = 0;
	};
}