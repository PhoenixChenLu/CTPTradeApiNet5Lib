#include "pch.h"
#include "MdSpi.h"

namespace PhoenixCTP
{
	MdSpi::MdSpi()
	{
		System::IntPtr pMdSpi = managedClass2IntPtr(this);
		CMdSpi* pCMdSpi = new CMdSpi(pMdSpi);
	}

	void MdSpi::OnFrontConnected()
	{
		this->FrontConnected();
	}

	void MdSpi::OnFrontDisconnected(int nReason)
	{
		this->FrontDisconnected(nReason);
	}

	void MdSpi::OnHeartBeatWarning(int nTimeLapse)
	{
		this->HeartBeatWarning(nTimeLapse);
	}

	void MdSpi::OnRspUserLogin(RspUserLoginField^ pRspUserLogin, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspUserLogin(pRspUserLogin, pRspInfo, nRequestID, bIsLast);
	}

	void MdSpi::OnRspUserLogout(UserLogoutField^ pUserLogout, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspUserLogout(pUserLogout, pRspInfo, nRequestID, bIsLast);
	}

	void MdSpi::OnRspQryMulticastInstrument(MulticastInstrumentField^ pMulticastInstrument, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryMulticastInstrument(pMulticastInstrument, pRspInfo, nRequestID, bIsLast);
	}

	void MdSpi::OnRspError(RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspError(pRspInfo, nRequestID, bIsLast);
	}

	void MdSpi::OnRspSubMarketData(SpecificInstrumentField^ pSpecificInstrument, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspSubMarketData(pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
	}

	void MdSpi::OnRspUnSubMarketData(SpecificInstrumentField^ pSpecificInstrument, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspUnSubMarketData(pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
	}

	void MdSpi::OnRspSubForQuoteRsp(SpecificInstrumentField^ pSpecificInstrument, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspSubForQuoteRsp(pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
	}

	void MdSpi::OnRspUnSubForQuoteRsp(SpecificInstrumentField^ pSpecificInstrument, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspUnSubForQuoteRsp(pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
	}

	void MdSpi::OnRtnDepthMarketData(DepthMarketDataField^ pDepthMarketData)
	{
		this->RtnDepthMarketData(pDepthMarketData);
	}

	void MdSpi::OnRtnForQuoteRsp(ForQuoteRspField^ pForQuoteRsp)
	{
		this->RtnForQuoteRsp(pForQuoteRsp);
	}
}
