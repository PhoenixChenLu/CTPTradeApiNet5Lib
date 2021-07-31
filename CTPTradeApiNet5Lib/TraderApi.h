#pragma once
#include "pch.h"
#include "ApiStructs.h"
#include "TraderSpi.h"

namespace PhoenixCTP
{
	public ref class TraderApi
	{
	public:
		/// <summary>
		/// 创建TraderApi
		/// </summary>
		/// <param name="pszFlowPath">储存订阅信息的文件目录，默认为当前目录</param>
		/// <returns>创建出的UserApi指针</returns>
		inline static CThostFtdcTraderApi* CreateFtdcTraderApi(System::String^ pszFlowPath);

		/// <summary>
		/// 获取API的版本信息
		/// </summary>
		/// <returns>获取到的版本号</returns>
		inline static System::String^ GetApiVersion();

		/// <summary>
		/// 删除对象接口本身
		/// </summary>
		/// <remarks>不再使用本接口对象时,调用该函数删除接口对象</remarks>
		inline virtual void Release() = 0;

		/// <summary>
		/// 初始化
		/// </summary>
		/// <remarks>初始化运行环境,只有调用后,接口才开始工作</remarks>
		inline virtual void Init() = 0;

		/// <summary>
		/// 等待线程接口结束运行
		/// </summary>
		/// <returns>线程退出代码</returns>
		inline virtual int Join() = 0;

		/// <summary>
		/// 获取当前交易日
		/// </summary>
		/// <returns>获取到的交易日</returns>
		/// <remarks>只有登陆成功后，才能得到正确的交易日</remarks>
		inline virtual System::String^ GetTradingDay() = 0;

		/// <summary>
		/// 注册前置机网络地址
		/// </summary>
		/// <param name="pszFrontAddress">前置机网络地址。</param>
		/// <remarks>网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:17001”。</remarks>
		/// <remarks>“tcp”代表传输协议，“127.0.0.1”代表服务器地址。”17001”代表服务器端口号。</remarks>
		inline virtual void RegisterFront(System::String^ pszFrontAddress) = 0;

		/// <summary>
		/// 注册名字服务器网络地址
		/// </summary>
		/// <param name="pszNsAddress">名字服务器网络地址。</param>
		/// <remarks>网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:12001”。</remarks>
		/// <remarks>“tcp”代表传输协议，“127.0.0.1”代表服务器地址。”12001”代表服务器端口号。</remarks>
		/// <remarks>RegisterNameServer优先于RegisterFront</remarks>
		inline virtual void RegisterNameServer(System::String^ pszNsAddress) = 0;

		/// <summary>
		/// 注册名字服务器用户信息
		/// </summary>
		/// <param name="pFensUserInfo">用户信息</param>
		inline virtual void RegisterFensUserInfo(FensUserInfoField pFensUserInfo) = 0;

		/// <summary>
		/// 注册回调接口
		/// </summary>
		/// <param name="pSpi">派生自回调接口类的实例</param>
		inline virtual void RegisterSpi(TraderSpi^ pSpi) = 0;

		/// <summary>
		/// 订阅私有流。
		/// </summary>
		/// <param name="nResumeType">私有流重传方式  
		/// THOST_TERT_RESTART:从本交易日开始重传
		/// THOST_TERT_RESUME:从上次收到的续传
		/// THOST_TERT_QUICK:只传送登录后私有流的内容</param>
		/// <remarks>该方法要在Init方法前调用。若不调用则不会收到私有流的数据。</remarks>
		inline virtual void SubscribePrivateTopic(THOST_TE_RESUME_TYPE nResumeType) = 0;

		/// <summary>
		/// 订阅公共流
		/// </summary>
		/// <param name="nResumeType">公共流重传方式
		/// THOST_TERT_RESTART:从本交易日开始重传
		/// THOST_TERT_RESUME:从上次收到的续传
		/// THOST_TERT_QUICK:只传送登录后私有流的内容</param>
		/// /// <remarks>该方法要在Init方法前调用。若不调用则不会收到公共流的数据。</remarks>
		inline virtual void SubscribePublicTopic(THOST_TE_RESUME_TYPE nResumeType) = 0;

		inline virtual int ReqAuthenticate();
	};
}
