#pragma once
#include "ApiStructs.h"

namespace PhoenixCTP
{
	/// <summary>
	/// 用于大多数事件响应参数的基类，包含响应信息、请求/响应ID、响应是否持续信息
	/// </summary>
	public ref class BasicArgs : System::EventArgs
	{
	public:
		RspInfoField^ pRspInfo;
		int nRequestID;
		bool bIsLast;

		BasicArgs(RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
		{
			this->pRspInfo = pRspInfo;
			this->nRequestID = nRequestID;
			this->bIsLast = bIsLast;
		}
	};


	public ref class FrontConnectedArgs : System::EventArgs
	{
	};

	public ref class FrontDisconnectedArgs : System::EventArgs
	{
	public:
		int nReason;

		FrontDisconnectedArgs(int nReason)
		{
			this->nReason = nReason;
		}
	};


	public ref class HeartBeatWarningArgs : System::EventArgs
	{
	public:
		int nTimeLapse;

		HeartBeatWarningArgs(int nTimeLapse)
		{
			this->nTimeLapse = nTimeLapse;
		}
	};

	public ref class RspUserLoginArgs : BasicArgs
	{
	public:
		RspUserLoginField^ pRspUserLogin;

		RspUserLoginArgs(RspUserLoginField^ pRspUserLogin, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast): BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pRspUserLogin = pRspUserLogin;
		}
	};

	public ref class RspUserLogoutArgs : BasicArgs
	{
	public:
		UserLogoutField^ pUserLogout;

		RspUserLogoutArgs(UserLogoutField^ pUserLogout, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast): BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pUserLogout = pUserLogout;
		}
	};

	public ref class RspQryMulticastInstrumentArgs : BasicArgs
	{
	public:
		MulticastInstrumentField^ pMulticastInstrument;

		RspQryMulticastInstrumentArgs(MulticastInstrumentField^ pMulticastInstrument, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pMulticastInstrument = pMulticastInstrument;
		}
	};

	public ref class RspErrorArgs : BasicArgs
	{
	public:
		RspErrorArgs(RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
		}
	};

	public ref class SpecificInstrumentEventArgs : BasicArgs
	{
	public:
		SpecificInstrumentField^ pSpecificInstrument;

		SpecificInstrumentEventArgs(SpecificInstrumentField^ pSpecificInstrument, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast): BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pSpecificInstrument = pSpecificInstrument;
		}
	};

	public ref class RtnDepthMarketDataArgs : System::EventArgs
	{
	public:
		DepthMarketDataField^ pDepthMarketData;

		RtnDepthMarketDataArgs(DepthMarketDataField^ pDepthMarketData)
		{
			this->pDepthMarketData = pDepthMarketData;
		}
	};

	public ref class RtnForQuoteRspArgs : System::EventArgs
	{
	public:
		ForQuoteRspField^ pForQuoteRsp;

		RtnForQuoteRspArgs(ForQuoteRspField^ pForQuoteRsp)
		{
			this->pForQuoteRsp = pForQuoteRsp;
		}
	};
}
