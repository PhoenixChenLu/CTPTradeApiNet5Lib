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
		std::cout << "initalizing pCSpi" << std::endl;
		std::cout << "value is: " << pCMdSpi << std::endl;
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
		std::cout << "Calling on Front Connected Method" << std::endl;
		pCSpi->OnFrontConnected();
	}

	void MdSpi::SetApi(MdApi^ pMdApi)
	{
		this->api = pMdApi;
	}


	void MdSpi::OnFrontConnected()
	{
		std::cout << "On front connected in MdSpi" << std::endl;;
		this->FrontConnected();
		std::cout << "EventFired" << std::endl;;
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
