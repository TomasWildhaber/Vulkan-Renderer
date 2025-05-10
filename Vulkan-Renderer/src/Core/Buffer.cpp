#include "pch.h"
#include "Buffer.h"

namespace VulkanRenderer
{
	Buffer::Buffer(uint32_t size) noexcept
	{
		Allocate(size);
	}

	Buffer::~Buffer()
	{
		Release();
	}

	void Buffer::Allocate(uint32_t size) noexcept
	{
		Release();

		m_Size = size;
		m_Data = (uint8_t*)malloc(m_Size);
	}

	void Buffer::Release() noexcept
	{
		free(m_Data);

		m_Size = 0;
		m_Data = nullptr;
	}

	void Buffer::WriteZeros()
	{
		memset(m_Data, 0, m_Size);
	}

	void Buffer::Write(const void* Data, uint32_t Size)
	{
		Allocate(Size);

		memcpy(m_Data, Data, Size);
	}
}