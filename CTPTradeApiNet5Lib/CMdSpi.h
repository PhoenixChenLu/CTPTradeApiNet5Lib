#pragma once
#include "pch.h"
#include "MdSpi.h"

namespace PhoenixCTP
{
	class CMdSpi:CThostFtdcMdSpi
	{
	public:
		System::IntPtr pMdSpi;

		CMdSpi(System::IntPtr intPMdSpi);

		inline void setNetSpi(System::IntPtr intPMdSpi);

		/// <summary>
		/// 当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
		/// </summary>
		inline virtual void OnFrontConnected() override;

		/// <summary>
		/// 当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
		/// </summary>
		/// <param name="nReason">错误原因
		/// 0x1001 网络读失败
		/// 0x1002 网络写失败
		/// 0x2001 接收心跳超时
		/// 0x2002 发送心跳失败
		/// 0x2003 收到错误报文</param>
		inline virtual void OnFrontDisconnected(int nReason) override;

		/// <summary>
		/// 心跳超时警告。当长时间未收到报文时，该方法被调用。
		/// </summary>
		/// <param name="nTimeLapse">距离上次接收报文的时间</param>
		inline virtual void OnHeartBeatWarning(int nTimeLapse) override;

		/// <summary>
		/// 登录请求响应
		/// </summary>
		/// <param name="pRspUserLogin">登录请求应答结构体指针</param>
		/// <param name="pRspInfo">响应信息结构体指针</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspUserLogin(CThostFtdcRspUserLoginField* pRspUserLogin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 登出请求响应
		/// </summary>
		/// <param name="pUserLogout">登出请求响应结构体指针</param>
		/// <param name="pRspInfo">响应信息结构体指针</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspUserLogout(CThostFtdcUserLogoutField* pUserLogout, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 请求查询组播合约响应
		/// </summary>
		/// <param name="pMulticastInstrument">组播合约结构体指针</param>
		/// <param name="pRspInfo">响应信息结构体指针</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryMulticastInstrument(CThostFtdcMulticastInstrumentField* pMulticastInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 错误应答
		/// </summary>
		/// <param name="pRspInfo">响应信息结构体指针</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspError(CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 订阅行情应答
		/// </summary>
		/// <param name="pSpecificInstrument">指定合约结构体指针</param>
		/// <param name="pRspInfo">响应信息结构体指针</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline  virtual void OnRspSubMarketData(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 取消订阅行情应答
		/// </summary>
		/// <param name="pSpecificInstrument">指定合约结构体指针</param>
		/// <param name="pRspInfo">响应信息结构体指针</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 订阅询价应答
		/// </summary>
		/// <param name="pSpecificInstrument">指定合约结构体指针</param>
		/// <param name="pRspInfo">响应信息结构体指针</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 取消订阅询价应答
		/// </summary>
		/// <param name="pSpecificInstrument">指定合约结构体指针</param>
		/// <param name="pRspInfo">响应信息结构体指针</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 深度行情通知
		/// </summary>
		/// <param name="pDepthMarketData">深度行情结构体指针</param>
		inline virtual void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField* pDepthMarketData) override;

		/// <summary>
		/// 询价通知
		/// </summary>
		/// <param name="pForQuoteRsp">发给做市商的询价请求结构体指针</param>
		inline virtual void OnRtnForQuoteRsp(CThostFtdcForQuoteRspField* pForQuoteRsp) override;
	};

}
