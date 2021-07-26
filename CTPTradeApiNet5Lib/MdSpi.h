#pragma once
#include "pch.h"


#include "Delegates.h"
#include "CMdSpi.h"

namespace PhoenixCTP
{
	ref class MdApi;

	/// <summary>
	/// 用于封装非托管的CTP原生CThostFtdcMdSpi类的托管类
	/// </summary>
	public ref class MdSpi
	{
	public:
		/// <summary>
		/// 用于储存CTP的C++原生SPI指针
		/// </summary>
		CThostFtdcMdSpi* pCSpi;

		/// <summary>
		/// 用于储存绑定的.Net5当中MdApi的指针
		/// </summary>
		MdApi^ Api;

		/// <summary>
		/// 默认构造函数
		/// </summary>
		/// <remarks>注意默认构造函数并不包含指向API的指针，需要使用SetApi设置之后才能实现某些功能</remarks>
		inline MdSpi();

		/// <summary>
		/// 构造函数，并用pMdApi初始化MdApi类型的成员变量
		/// </summary>
		/// <param name="pMdApi">已经构建好的MdApi类</param>
		inline MdSpi(MdApi^ pMdApi);

		/// <summary>
		/// 将MdApi型成员变量设置为参数值
		/// </summary>
		/// <param name="pMdApi">已经构建好的MdApi类</param>
		inline void SetApi(MdApi^ pMdApi);

		/// <summary>
		/// FrontConnected事件，交易后台建立起通信连接时（还未登录前），通过本类当中的OnFrontConnected方法引发该事件
		/// 用于执行事件引发之后的<b>同步</b>方法
		/// </summary>
		/// <seealso cref="OnFrontConnected">OnFrontConnected</seealso>
		event DOnFrontConnected^ FrontConnected;

		/// <summary>
		/// 当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
		/// 该方法会自动生成参数引发<seealso cref="FrontConnected">FrontConnected</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		inline virtual void OnFrontConnected();

		/// <summary>
		/// 当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
		/// 使用外传参数引发<seealso cref="FrontConnected">FrontConnected</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的类</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnFrontConnected(MdSpi^ sender, FrontConnectedArgs^ e);

		/// <summary>
		/// 当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
		/// </summary>
		/// <seealso cref="OnFrontDisconnected"/>
		event DOnFrontDisconnected^ FrontDisconnected;

		/// <summary>
		/// 当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
		/// 该方法会自动生成事件参数引发<seealso cref="FrontDisconnected">FrontDisconnected</seealso>事件，这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="nReason">错误原因
		/// 0x1001 网络读失败
		/// 0x1002 网络写失败
		/// 0x2001 接收心跳超时
		/// 0x2002 发送心跳失败
		/// 0x2003 收到错误报文</param>
		inline virtual void OnFrontDisconnected(int nReason);

		/// <summary>
		/// 当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
		/// 该方法使用外传事件参数引发<seealso cref="FrontDisconnected">FrontDisconnected</seealso>事件，这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的类</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnFrontDisconnected(MdSpi^ sender, FrontDisconnectedArgs^ e);

		event DOnHeartBeatWarning^ HeartBeatWarning;

		/// <summary>
		/// 心跳超时警告。当长时间未收到报文时，该方法被调用。
		/// 该方法自动生成事件参数引发<seealso cref="HeartBeatWarning">HeartBeatWarning</seealso>事件，这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="nTimeLapse">距离上次接收报文的时间</param>
		inline virtual void OnHeartBeatWarning(int nTimeLapse);

		/// <summary>
		/// 心跳超时警告。当长时间未收到报文时，该方法被调用。
		/// 该方法使用外传事件参数引发<seealso cref="HeartBeatWarning">HeartBeatWarning</seealso>事件，这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的类</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnHeartBeatWarning(MdSpi^ sender, HeartBeatWarningArgs^ e);

		event DOnRspUserLogin^ RspUserLogin;

		/// <summary>
		/// 登录请求响应
		/// 该方法使用原始参数生成事件参数并引发<seealso cref="RspUserLogin">RspUserLogin</seealso>事件，这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pRspUserLogin">登录请求应答的托管结构体</param>
		/// <param name="pRspInfo">响应信息的托管结构体</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspUserLogin(RspUserLoginField^ pRspUserLogin, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 登录请求响应
		/// 该方法使用外传事件参数引发<seealso cref="RspUserLogin">RspUserLogin</seealso>事件，这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的类</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspUserLogin(MdSpi^ sender, RspUserLoginArgs^ e);

		event DOnRspUserLogout^ RspUserLogout;

		/// <summary>
		/// 登出请求响应
		/// 该方法使用原始参数自动生成事件参数引发<seealso cref="RspUserLogout">RspUserLogout</seealso>事件，这一事件<b>同步</b>调用响应函数
		/// </summary>
		/// <param name="pUserLogout">登出请求响应的托管结构体</param>
		/// <param name="pRspInfo">响应信息的托管结构体</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspUserLogout(UserLogoutField^ pUserLogout, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 登出请求响应
		/// 该方法使用外传事件参数引发<seealso cref="RspUserLogout">RspUserLogout</seealso>事件，这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的类</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspUserLogout(MdSpi^ sender, RspUserLogoutArgs^ e);

		event DOnRspQryMulticastInstrument^ RspQryMulticastInstrument;

		/// <summary>
		/// 请求查询组播合约响应
		/// 该方法使用原始参数自动生成事件参数引发<seealso cref="RspQryMulticastInstrument">RspQryMulticastInstrument</seealso>事件，这一事件<b>同步</b>调用响应函数
		/// </summary>
		/// <param name="pMulticastInstrument">组播合约的托管结构体</param>
		/// <param name="pRspInfo">响应信息的托管结构体</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryMulticastInstrument(MulticastInstrumentField^ pMulticastInstrument, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询组播合约响应
		/// 该方法使用外传事件参数引发<seealso cref="RspQryMulticastInstrument">RspQryMulticastInstrument</seealso>事件，这一事件<b>同步</b>调用响应函数
		/// </summary>
		/// <param name="sender">引发事件的类</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQryMulticastInstrument(MdSpi^ sender, RspQryMulticastInstrumentArgs^ e);

		event DOnRspError^ RspError;

		/// <summary>
		/// 错误应答
		/// 该方法使用原始参数自动生成事件参数引发<seealso cref="RspError">RspError</seealso>事件，这一事件<b>同步</b>调用响应函数
		/// </summary>
		/// <param name="pRspInfo">响应信息的托管结构体</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspError(RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 错误应答
		/// 该方法使用外传事件参数引发<seealso cref="RspError">RspError</seealso>事件，这一事件<b>同步</b>调用响应函数
		/// </summary>
		/// <param name="sender">引发事件的类</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspError(MdSpi^ sender, RspErrorArgs^ e);

		event DOnRspSubMarketData^ RspSubMarketData;

		/// <summary>
		/// 订阅行情的应答
		/// 该方法使用原始参数自动生成事件参数引发<seealso cref="RspSubMarketData">RspSubMarketData</seealso>事件，这一事件<b>同步</b>调用响应函数
		/// </summary>
		/// <param name="pSpecificInstrument">指定合约的托管结构体</param>
		/// <param name="pRspInfo">响应信息的托管结构体</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspSubMarketData(SpecificInstrumentField^ pSpecificInstrument, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 订阅行情应答
		/// 该方法使用外传事件参数引发<seealso cref="RspSubMarketData">RspSubMarketData</seealso>事件，这一事件<b>同步</b>调用响应函数
		/// </summary>
		/// <param name="sender">引发事件的类</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspSubMarketData(MdSpi^ sender, SpecificInstrumentEventArgs^ e);

		event DOnRspUnSubMarketData^ RspUnSubMarketData;

		/// <summary>
		/// 取消订阅行情的应答
		/// 该方法使用原始参数自动生成事件参数引发<seealso cref="RspUnSubMarketData">RspUnSubMarketData</seealso>事件，这一事件<b>同步</b>调用响应函数
		/// </summary>
		/// <param name="pSpecificInstrument">指定合约的托管结构体</param>
		/// <param name="pRspInfo">响应信息的托管结构体</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspUnSubMarketData(SpecificInstrumentField^ pSpecificInstrument, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 取消订阅行情应答
		/// 该方法使用外传事件参数引发<seealso cref="RspUnSubMarketData">RspUnSubMarketData</seealso>事件，这一事件<b>同步</b>调用响应函数
		/// </summary>
		/// <param name="sender">引发事件的类</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspUnSubMarketData(MdSpi^ sender, SpecificInstrumentEventArgs^ e);

		event DOnRspSubForQuoteRsp^ RspSubForQuoteRsp;

		/// <summary>
		/// 订阅询价的应答
		/// 该方法使用原始参数自动生成事件参数引发<seealso cref="RspSubForQuoteRsp">RspSubForQuoteRsp</seealso>事件，这一事件<b>同步</b>调用响应函数
		/// </summary>
		/// <param name="pSpecificInstrument">指定合约的托管结构体</param>
		/// <param name="pRspInfo">响应信息的托管结构体</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspSubForQuoteRsp(SpecificInstrumentField^ pSpecificInstrument, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 订阅询价应答
		/// 该方法使用外传事件参数引发<seealso cref="RspSubForQuoteRsp">RspSubForQuoteRsp</seealso>事件，这一事件<b>同步</b>调用响应函数
		/// </summary>
		/// <param name="sender">引发事件的类</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspSubForQuoteRsp(MdSpi^ sender, SpecificInstrumentEventArgs^ e);

		event DOnRspUnSubForQuoteRsp^ RspUnSubForQuoteRsp;

		/// <summary>
		/// 取消订阅询价的应答
		/// 该方法使用原始参数自动生成事件参数引发<seealso cref="RspUnSubForQuoteRsp">RspUnSubForQuoteRsp</seealso>事件，这一事件<b>同步</b>调用响应函数
		/// </summary>
		/// <param name="pSpecificInstrument">指定合约的托管结构体</param>
		/// <param name="pRspInfo">响应信息的托管结构体</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspUnSubForQuoteRsp(SpecificInstrumentField^ pSpecificInstrument, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 取消订阅询价应答
		/// 该方法使用外传事件参数引发<seealso cref="RspUnSubForQuoteRsp">RspUnSubForQuoteRsp</seealso>事件，这一事件<b>同步</b>调用响应函数
		/// </summary>
		/// <param name="sender">引发事件的类</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspUnSubForQuoteRsp(MdSpi^ sender, SpecificInstrumentEventArgs^ e);

		event DOnRtnDepthMarketData^ RtnDepthMarketData;

		/// <summary>
		/// 深度行情通知
		/// 该方法使用原始参数自动生成事件参数引发<seealso cref="RtnDepthMarketData">RtnDepthMarketData</seealso>事件，这一事件<b>同步</b>调用响应函数
		/// </summary>
		/// <param name="pDepthMarketData"> 深度行情的托管结构体</param>
		inline virtual void OnRtnDepthMarketData(DepthMarketDataField^ pDepthMarketData);

		/// <summary>
		/// 深度行情通知
		/// 该方法使用外传事件参数引发<seealso cref="RtnDepthMarketData">RtnDepthMarketData</seealso>事件，这一事件<b>同步</b>调用响应函数
		/// </summary>
		/// <param name="sender">引发事件的类</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRtnDepthMarketData(MdSpi^ sender, RtnDepthMarketDataArgs^ e);

		event DOnRtnForQuoteRsp^ RtnForQuoteRsp;

		/// <summary>
		/// 询价通知
		/// 该方法使用原始参数自动生成事件参数引发<seealso cref="RtnForQuoteRsp">RtnForQuoteRsp</seealso>事件，这一事件<b>同步</b>调用响应函数
		/// </summary>
		/// <param name="pForQuoteRsp">发给做市商的询价请求托管结构体</param>
		inline virtual void OnRtnForQuoteRsp(ForQuoteRspField^ pForQuoteRsp);

		/// <summary>
		/// 询价通知
		/// 该方法使用外传事件参数引发<seealso cref="RtnForQuoteRsp">RtnForQuoteRsp</seealso>事件，这一事件<b>同步</b>调用响应函数
		/// </summary>
		/// <param name="sender">引发事件的类</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRtnForQuoteRsp(MdSpi^ sender, RtnForQuoteRspArgs^ e);
	};
}
