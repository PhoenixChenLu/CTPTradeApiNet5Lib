#pragma onces
#include "EventArgsStructs.h"

namespace PhoenixCTP
{
	ref class MdSpi;
	/// <summary>
	/// 客户端与交易后台建立通信连接时的委托
	/// </summary>
	public delegate void DOnFrontConnected(MdSpi^ sender, FrontConnectedArgs^ e);

	/// <summary>
	/// 客户端与后台通信连接断开时的委托
	/// </summary>
	public delegate void DOnFrontDisconnected(MdSpi^ sender, FrontDisconnectedArgs^ e);

	/// <summary>
	/// 心跳超时警告的委托
	/// </summary>
	public delegate void DOnHeartBeatWarning(MdSpi^ sender, HeartBeatWarningArgs^ e);

	/// <summary>
	/// 登录请求响应的委托
	/// </summary>
	public delegate void DOnRspUserLogin(MdSpi^ sender, RspUserLoginArgs^ e);

	/// <summary>
	/// 登出请求响应的委托
	/// </summary>
	public delegate void DOnRspUserLogout(MdSpi^ sender, RspUserLogoutArgs^ e);

	/// <summary>
	/// 请求查询组播合约响应的委托
	/// </summary>
	public delegate void DOnRspQryMulticastInstrument(MdSpi^ sender, RspQryMulticastInstrumentArgs^ e);

	/// <summary>
	/// 错误应答的委托
	/// </summary>
	public delegate void DOnRspError(MdSpi^ sender, RspErrorArgs^ e);

	/// <summary>
	/// 订阅行情应答的委托
	/// </summary>
	public delegate void DOnRspSubMarketData(MdSpi^ sender, SpecificInstrumentEventArgs^ e);

	/// <summary>
	/// 取消订阅行情应答的委托
	/// </summary>
	public delegate void DOnRspUnSubMarketData(MdSpi^ sender, SpecificInstrumentEventArgs^ e);

	/// <summary>
	/// 订阅询价应答的委托
	/// </summary>
	public delegate void DOnRspSubForQuoteRsp(MdSpi^ sender, SpecificInstrumentEventArgs^ e);

	/// <summary>
	/// 取消订阅询价应答的委托
	/// </summary>
	public delegate void DOnRspUnSubForQuoteRsp(MdSpi^ sender, SpecificInstrumentEventArgs^ e);

	/// <summary>
	/// 深度行情通知的委托
	/// </summary>
	public delegate void DOnRtnDepthMarketData(MdSpi^ sender, RtnDepthMarketDataArgs^ e);

	/// <summary>
	/// 询价通知的委托
	/// </summary>
	public delegate void DOnRtnForQuoteRsp(MdSpi^ sender, RtnForQuoteRspArgs^ e);
}
