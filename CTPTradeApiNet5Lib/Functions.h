#pragma once
namespace PhoenixCTP
{
	/// <summary>
	/// 将托管的string类转化为char*类型指针
	/// </summary>
	/// <param name="source">托管的string类型字符串</param>
	/// <returns>指向转化后字符串的char指针</returns>
	inline const char* netString2ConstChar(System::String^ source)
	{
		if (source == nullptr)
			return "";
		System::IntPtr ptr = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(source);
		const char* result = static_cast<const char*>(ptr.ToPointer());
		System::Runtime::InteropServices::Marshal::FreeHGlobal(ptr);
		return result;
	}

	/**
	 * \brief 将非托管的字符串转化为托管字符串
	 * \param source 非托管的字符串指针
	 * \return .Net托管字符串
	 */
	inline System::String^ char2NetString(char* source)
	{		
		return gcnew System::String(source);
	}
	
	/**
	 * \brief 将非托管的常量字符串转化为托管字符串
	 * \param source 非托管的常字符串指针
	 * \return .Net托管字符串
	 */
	inline System::String^ constChar2NetString(const char* source)
	{
		return gcnew System::String(source);
	}

	/**
	 * \brief 将托管的字符串转化为非托管的字符指针
	 * \param source 托管的.Net字符串
	 * \return 字符指针
	 */
	inline char* netString2Char(System::String^ source)
	{
		if (source == nullptr)
			return "";
		System::IntPtr ptr = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(source);
		char* result = static_cast<char*>(ptr.ToPointer());
		System::Runtime::InteropServices::Marshal::FreeHGlobal(ptr);
		return result;
	}

	/**
	 * \brief 将托管的字符串数组转化为非托管的指针数组
	 * \param source 托管的字符串数组
	 * \return 指向字符串的指针数组
	 */
	inline char** netArray2CharArray(array<System::String^>^ source)
	{
		int length = source->Length;
		char** result = new char* [length];
		for (int i = 0; i < length; i++)
		{
			result[i] = netString2Char(static_cast<System::String^>(source->GetValue(i)));
		}
		return result;
	}

	/**
	 * \brief 将托管类转化为非托管整型指针
	 * \param value 托管类
	 * \return 指向托管类的非托管指针
	 */
	inline System::IntPtr managedClass2IntPtr(System::Object^ value)
	{
		return static_cast<System::IntPtr>(System::Runtime::InteropServices::GCHandle::Alloc(value));
	}

	/**
	 * \brief 将非托管的整形指针转化为托管类
	 * \param source 非托管的整型指针
	 * \return 托管的Object类
	 */
	inline System::Object^ intPtr2ManagedClass(System::IntPtr source)
	{
		return safe_cast<System::Object^>(static_cast<System::Runtime::InteropServices::GCHandle>(source).Target);
	}
}
