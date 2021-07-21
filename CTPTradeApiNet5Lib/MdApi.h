#pragma once
#include "pch.h"
#include "ApiStructs.h"
#include "MdSpi.h"

namespace PhoenixCTP
{
	public ref class MdApi
	{
	public:
		/// <summary>
		/// 用于储存CTP的C++原生API指针
		/// </summary>
		CThostFtdcMdApi* api = nullptr;

		/// <summary>
		/// 创建原始C++类当中的MdApi
		/// </summary>
		/// <param name="pszFlowPath">储存订阅信息文件的目录，默认为当前目录</param>
		/// <param name="bIsUsingUdp"></param>
		/// <param name="bIsMulticast"></param>
		/// <returns>创建出的UserApi指针</returns>
		inline static CThostFtdcMdApi* CreateFtdcMdApi(System::String^ pszFlowPath, const bool bIsUsingUdp, const bool bIsMulticast);


		/// <summary>
		/// 在.net类当中创建原始MdApi，并将创建好的原始C++MdApi放入类的api成员变量当中
		/// </summary>
		/// <param name="pszFlowPath">储存订阅信息文件的目录，默认为当前目录</param>
		/// <param name="bIsUsingUdp"></param>
		/// <param name="bIsMulticast"></param>
		inline void CreateMdApi(System::String^ pszFlowPath, const bool bIsUsingUdp, const bool bIsMulticast);

		/// <summary>
		/// 获取API版本信息
		/// </summary>
		/// <returns>获取到的版本号</returns>
		inline static System::String^ GetApiVersion();

		/// <summary>
		/// 删除接口对象本身
		/// </summary>
		/// <remarks>不再使用本接口对象时，调用该函数删除接口对象</remarks>
		inline virtual void Release();

		/// <summary>
		/// 初始化
		/// </summary>
		/// <remarks>初始化运行环境，只有调用后，接口才开始工作</remarks>
		inline virtual void Init();

		/// <summary>
		/// 等待接口线程结束运行
		/// </summary>
		/// <returns>退出线程代码</returns>
		inline virtual int Join();

		/// <summary>
		/// 获取当前交易日
		/// </summary>
		/// <returns>获取到的交易日</returns>
		/// <remarks>只有登录成功后,才能得到正确的交易日</remarks>
		inline virtual System::String^ GetTradingDay();

		/// <summary>
		/// 注册前置机网络地址
		/// </summary>
		/// <param name="pszFrontAddress">前置机网络地址</param>
		/// <remarks>网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:17001”。</remarks>
		/// <remarks>“tcp”代表传输协议，“127.0.0.1”代表服务器地址。”17001”代表服务器端口号。</remarks>
		inline virtual void RegisterFront(System::String^ pszFrontAddress);


		/// <summary>
		/// 注册名字服务器网络地址
		/// </summary>
		/// <param name="pszNsAddress">名字服务器网络地址。</param>
		/// <remarks>网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:17001”。</remarks>
		/// <remarks>“tcp”代表传输协议，“127.0.0.1”代表服务器地址。”17001”代表服务器端口号。</remarks>
		/// <remarks>RegisterNameServer优先于RegisterFront</remarks>
		inline virtual void RegisterNameServer(System::String^ pszNsAddress);

		/// <summary>
		/// 注册名字服务器用户信息
		/// </summary>
		/// <param name="pFensUserInfo">用户信息</param>
		inline virtual void RegisterFensUserInfo(FensUserInfoField^ pFensUserInfo);

		/// <summary>
		/// 注册回调接口
		/// </summary>
		/// <param name="pSpi">派生自.net接口类MdSpi的实例</param>
		inline virtual void RegisterSpi(MdSpi^ pSpi);


		/// <summary>
		/// 订阅行情。
		/// </summary>
		/// <param name="ppInstrumentID">合约ID的string的array</param>
		/// <param name="nCount">需要订阅/退订行情的合约个数</param>
		/// <returns></returns>
		/// <remarks></remarks>
		inline virtual int SubscribeMarketData(array<System::String^>^ ppInstrumentID, int nCount);

		/// <summary>
		/// 退订行情。
		/// </summary>
		/// <param name="ppInstrumentID">合约ID的string的array</param>
		/// <param name="nCount">需要订阅/退订行情的合约个数</param>
		/// <returns></returns>
		/// <remarks></remarks>
		inline virtual int UnSubscribeMarketData(array<System::String^>^ ppInstrumentID, int nCount);

		/// <summary>
		/// 订阅询价。
		/// </summary>
		/// <param name="ppInstrumentID">合约ID的string的array</param>
		/// <param name="nCount">需要订阅/退订行情的合约个数</param>
		/// <returns></returns>
		/// <remarks></remarks>
		inline virtual int SubscribeForQuoteRsp(array<System::String^>^ ppInstrumentID, int nCount);

		/// <summary>
		/// 退订询价。
		/// </summary>
		/// <param name="ppInstrumentID">合约ID的string的array</param>
		/// <param name="nCount">需要订阅/退订行情的合约个数</param>
		/// <returns></returns>
		/// <remarks></remarks>
		inline virtual int UnSubscribeForQuoteRsp(array<System::String^>^ ppInstrumentID, int nCount);

		~MdApi();
	};
}


