#pragma once
#include "ApiStructs.h"

namespace PhoenixCTP
{
	/// <summary>
	/// 客户端与交易后台建立通信连接时的委托
	/// </summary>
	public delegate void DOnFrontConnected(void);

	/// <summary>
	/// 客户端与后台通信连接断开时的委托
	/// </summary>
	public delegate void DOnFrontDisconnected(int nReason);

	/// <summary>
	/// 心跳超时警告的委托
	/// </summary>
	public delegate void DOnHeartBeatWarning(int nTimeLapse);

	/// <summary>
	/// 登录请求响应的委托
	/// </summary>
	public delegate void DOnRspUserLogin(RspUserLoginField^ pRspUserLogin, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

	/// <summary>
	/// 登出请求响应的委托
	/// </summary>
	public delegate void DOnRspUserLogout(UserLogoutField^ pUserLogout, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

	/// <summary>
	/// 请求查询组播合约响应的委托
	/// </summary>
	public delegate void DOnRspQryMulticastInstrument(MulticastInstrumentField^ pMulticastInstrument, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

	/// <summary>
	/// 错误应答的委托
	/// </summary>
	public delegate void DOnRspError(RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

	/// <summary>
	/// 订阅行情应答的委托
	/// </summary>
	public delegate void DOnRspSubMarketData(SpecificInstrumentField^ pSpecificInstrument, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

	/// <summary>
	/// 取消订阅行情应答的委托
	/// </summary>
	public delegate void DOnRspUnSubMarketData(SpecificInstrumentField^ pSpecificInstrument, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

	/// <summary>
	/// 订阅询价应答的委托
	/// </summary>
	public delegate void DOnRspSubForQuoteRsp(SpecificInstrumentField^ pSpecificInstrument, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

	/// <summary>
	/// 取消订阅询价应答的委托
	/// </summary>
	public delegate void DOnRspUnSubForQuoteRsp(SpecificInstrumentField^ pSpecificInstrument, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

	/// <summary>
	/// 深度行情通知的委托
	/// </summary>
	public delegate void DOnRtnDepthMarketData(DepthMarketDataField^ pDepthMarketData);

	/// <summary>
	/// 询价通知的委托
	/// </summary>
	public delegate void DOnRtnForQuoteRsp(ForQuoteRspField^ pForQuoteRsp);
}
