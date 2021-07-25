#include "pch.h"
#include "CMdSpi.h"

#include <iostream>

namespace PhoenixCTP
{
	CMdSpi::CMdSpi(System::IntPtr intPMdSpi)
	{
		this->pMdSpi = intPMdSpi;
	}


	void CMdSpi::setNetSpi(System::IntPtr intPMdSpi)
	{
		this->pMdSpi = intPMdSpi;
	}


	void CMdSpi::OnFrontConnected()
	{
		safe_cast<MdSpi^>(intPtr2ManagedClass(this->pMdSpi))->OnFrontConnected();
	}

	void CMdSpi::OnFrontDisconnected(int nReason)
	{
		safe_cast<MdSpi^>(intPtr2ManagedClass(this->pMdSpi))->OnFrontDisconnected(nReason);
	}

	void CMdSpi::OnHeartBeatWarning(int nTimeLapse)
	{
		safe_cast<MdSpi^>(intPtr2ManagedClass(this->pMdSpi))->OnHeartBeatWarning(nTimeLapse);
	}

	void CMdSpi::OnRspUserLogin(CThostFtdcRspUserLoginField* pRspUserLogin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<MdSpi^>(intPtr2ManagedClass(this->pMdSpi))->OnRspUserLogin(gcnew RspUserLoginField(pRspUserLogin), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CMdSpi::OnRspUserLogout(CThostFtdcUserLogoutField* pUserLogout, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<MdSpi^>(intPtr2ManagedClass(this->pMdSpi))->OnRspUserLogout(gcnew UserLogoutField(pUserLogout), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CMdSpi::OnRspQryMulticastInstrument(CThostFtdcMulticastInstrumentField* pMulticastInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<MdSpi^>(intPtr2ManagedClass(this->pMdSpi))->OnRspQryMulticastInstrument(gcnew MulticastInstrumentField(pMulticastInstrument), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CMdSpi::OnRspError(CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<MdSpi^>(intPtr2ManagedClass(this->pMdSpi))->OnRspError(gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CMdSpi::OnRspSubMarketData(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<MdSpi^>(intPtr2ManagedClass(this->pMdSpi))->OnRspSubMarketData(gcnew SpecificInstrumentField(pSpecificInstrument), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CMdSpi::OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<MdSpi^>(intPtr2ManagedClass(this->pMdSpi))->OnRspUnSubMarketData(gcnew SpecificInstrumentField(pSpecificInstrument), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CMdSpi::OnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<MdSpi^>(intPtr2ManagedClass(this->pMdSpi))->OnRspSubForQuoteRsp(gcnew SpecificInstrumentField(pSpecificInstrument), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CMdSpi::OnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<MdSpi^>(intPtr2ManagedClass(this->pMdSpi))->OnRspUnSubForQuoteRsp(gcnew SpecificInstrumentField(pSpecificInstrument), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CMdSpi::OnRtnDepthMarketData(CThostFtdcDepthMarketDataField* pDepthMarketData)
	{
		safe_cast<MdSpi^>(intPtr2ManagedClass(this->pMdSpi))->OnRtnDepthMarketData(gcnew DepthMarketDataField(pDepthMarketData));
	}

	void CMdSpi::OnRtnForQuoteRsp(CThostFtdcForQuoteRspField* pForQuoteRsp)
	{
		safe_cast<MdSpi^>(intPtr2ManagedClass(this->pMdSpi))->OnRtnForQuoteRsp(gcnew ForQuoteRspField(pForQuoteRsp));
	}
}
