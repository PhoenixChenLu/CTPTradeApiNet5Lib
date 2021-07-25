#include "pch.h"
#include "MdSpi.h"

#include <iostream>

namespace PhoenixCTP
{
	class CMdSpi;

	MdSpi::MdSpi()
	{
		System::IntPtr pMdSpi = managedClass2IntPtr(this);
		CMdSpi* pCMdSpi = new CMdSpi(pMdSpi);
		pCSpi = pCMdSpi;
	}

	MdSpi::MdSpi(MdApi^ pMdApi)
	{
		System::IntPtr pMdSpi = managedClass2IntPtr(this);
		CMdSpi* pCMdSpi = new CMdSpi(pMdSpi);
		pCSpi = pCMdSpi;
		SetApi(pMdApi);
	}

	void MdSpi::FireEvent()
	{
		pCSpi->OnFrontConnected();
	}

	void MdSpi::SetApi(MdApi^ pMdApi)
	{
		this->api = pMdApi;
	}


	void MdSpi::OnFrontConnected()
	{
		this->FrontConnected(this, gcnew FrontConnectedArgs());
	}

	void MdSpi::OnFrontDisconnected(int nReason)
	{
		this->FrontDisconnected(this, gcnew FrontDisconnectedArgs(nReason));
	}

	void MdSpi::OnHeartBeatWarning(int nTimeLapse)
	{
		this->HeartBeatWarning(this, gcnew HeartBeatWarningArgs(nTimeLapse));
	}

	void MdSpi::OnRspUserLogin(RspUserLoginField^ pRspUserLogin, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspUserLogin(this, gcnew RspUserLoginArgs(pRspUserLogin, pRspInfo, nRequestID, bIsLast));
	}

	void MdSpi::OnRspUserLogout(UserLogoutField^ pUserLogout, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspUserLogout(this, gcnew RspUserLogoutArgs(pUserLogout, pRspInfo, nRequestID, bIsLast));
	}

	void MdSpi::OnRspQryMulticastInstrument(MulticastInstrumentField^ pMulticastInstrument, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryMulticastInstrument(this, gcnew RspQryMulticastInstrumentArgs(pMulticastInstrument, pRspInfo, nRequestID, bIsLast));
	}

	void MdSpi::OnRspError(RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspError(this, gcnew RspErrorArgs(pRspInfo, nRequestID, bIsLast));
	}

	void MdSpi::OnRspSubMarketData(SpecificInstrumentField^ pSpecificInstrument, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspSubMarketData(this, gcnew SpecificInstrumentEventArgs(pSpecificInstrument, pRspInfo, nRequestID, bIsLast));
	}

	void MdSpi::OnRspUnSubMarketData(SpecificInstrumentField^ pSpecificInstrument, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspUnSubMarketData(this, gcnew SpecificInstrumentEventArgs(pSpecificInstrument, pRspInfo, nRequestID, bIsLast));
	}

	void MdSpi::OnRspSubForQuoteRsp(SpecificInstrumentField^ pSpecificInstrument, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspSubForQuoteRsp(this, gcnew SpecificInstrumentEventArgs(pSpecificInstrument, pRspInfo, nRequestID, bIsLast));
	}

	void MdSpi::OnRspUnSubForQuoteRsp(SpecificInstrumentField^ pSpecificInstrument, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspUnSubForQuoteRsp(this, gcnew SpecificInstrumentEventArgs(pSpecificInstrument, pRspInfo, nRequestID, bIsLast));
	}

	void MdSpi::OnRtnDepthMarketData(DepthMarketDataField^ pDepthMarketData)
	{
		this->RtnDepthMarketData(this, gcnew RtnDepthMarketDataArgs(pDepthMarketData));
	}

	void MdSpi::OnRtnForQuoteRsp(ForQuoteRspField^ pForQuoteRsp)
	{
		this->RtnForQuoteRsp(this, gcnew RtnForQuoteRspArgs(pForQuoteRsp));
	}
}
