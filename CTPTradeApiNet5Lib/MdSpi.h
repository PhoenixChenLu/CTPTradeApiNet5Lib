#pragma once
#include "pch.h"
#include "Delegates.h"
#include "CMdSpi.h"

namespace PhoenixCTP
{
	public ref class MdSpi
	{
	public:
		/// <summary>
		/// 用于储存CTP的C++原生SPI指针
		/// </summary>
		CThostFtdcMdSpi* spi;

		inline MdSpi();

		event DOnFrontConnected^ FrontConnected;

		inline virtual void OnFrontConnected();

		event DOnFrontDisconnected^ FrontDisconnected;

		inline virtual void OnFrontDisconnected(int nReason);

		event DOnHeartBeatWarning^ HeartBeatWarning;

		inline virtual void OnHeartBeatWarning(int nTimeLapse);

		event DOnRspUserLogin^ RspUserLogin;

		inline virtual void OnRspUserLogin(RspUserLoginField^ pRspUserLogin, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		event DOnRspUserLogout^ RspUserLogout;

		inline virtual void OnRspUserLogout(UserLogoutField^ pUserLogout, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		event DOnRspQryMulticastInstrument^ RspQryMulticastInstrument;

		inline virtual void OnRspQryMulticastInstrument(MulticastInstrumentField^ pMulticastInstrument, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		event DOnRspError^ RspError;

		inline virtual void OnRspError(RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		event DOnRspSubMarketData^ RspSubMarketData;

		inline virtual void OnRspSubMarketData(SpecificInstrumentField^ pSpecificInstrument, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		event DOnRspUnSubMarketData^ RspUnSubMarketData;

		inline virtual void OnRspUnSubMarketData(SpecificInstrumentField^ pSpecificInstrument, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		event DOnRspSubForQuoteRsp^ RspSubForQuoteRsp;

		inline virtual void OnRspSubForQuoteRsp(SpecificInstrumentField^ pSpecificInstrument, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		event DOnRspUnSubForQuoteRsp^ RspUnSubForQuoteRsp;

		inline virtual void OnRspUnSubForQuoteRsp(SpecificInstrumentField^ pSpecificInstrument, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		event DOnRtnDepthMarketData^ RtnDepthMarketData;

		inline virtual void OnRtnDepthMarketData(DepthMarketDataField^ pDepthMarketData);

		event DOnRtnForQuoteRsp^ RtnForQuoteRsp;

		inline virtual void OnRtnForQuoteRsp(ForQuoteRspField^ pForQuoteRsp);
	};

}
