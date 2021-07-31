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

	inline System::String^ char2NetString(char* source)
	{		
		return gcnew System::String(source);
	}

	inline System::String^ constChar2NetString(const char* source)
	{
		return gcnew System::String(source);
	}

	inline char* netString2Char(System::String^ source)
	{
		if (source == nullptr)
			return "";
		System::IntPtr ptr = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(source);
		char* result = static_cast<char*>(ptr.ToPointer());
		System::Runtime::InteropServices::Marshal::FreeHGlobal(ptr);
		return result;
	}

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

	inline System::IntPtr managedClass2IntPtr(System::Object^ value)
	{
		return static_cast<System::IntPtr>(System::Runtime::InteropServices::GCHandle::Alloc(value));
	}

	inline System::Object^ intPtr2ManagedClass(System::IntPtr source)
	{
		return safe_cast<System::Object^>(static_cast<System::Runtime::InteropServices::GCHandle>(source).Target);
	}
}
