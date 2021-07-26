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

	void MdSpi::SetApi(MdApi^ pMdApi)
	{
		this->Api = pMdApi;
	}


	void MdSpi::OnFrontConnected()
	{
		this->FrontConnected(this, gcnew FrontConnectedArgs());
	}

	void MdSpi::OnFrontConnected(MdSpi^ sender, FrontConnectedArgs^ e)
	{
		this->FrontConnected(sender, e);
	}

	void MdSpi::OnFrontDisconnected(int nReason)
	{
		this->FrontDisconnected(this, gcnew FrontDisconnectedArgs(nReason));
	}

	void MdSpi::OnFrontDisconnected(MdSpi^ sender, FrontDisconnectedArgs^ e)
	{
		this->FrontDisconnected(sender, e);
	}

	void MdSpi::OnHeartBeatWarning(int nTimeLapse)
	{
		this->HeartBeatWarning(this, gcnew HeartBeatWarningArgs(nTimeLapse));
	}

	void MdSpi::OnHeartBeatWarning(MdSpi^ sender, HeartBeatWarningArgs^ e)
	{
		this->HeartBeatWarning(sender, e);
	}

	void MdSpi::OnRspUserLogin(RspUserLoginField^ pRspUserLogin, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspUserLogin(this, gcnew RspUserLoginArgs(pRspUserLogin, pRspInfo, nRequestID, bIsLast));
	}

	void MdSpi::OnRspUserLogin(MdSpi^ sender, RspUserLoginArgs^ e)
	{
		this->RspUserLogin(sender, e);
	}

	void MdSpi::OnRspUserLogout(UserLogoutField^ pUserLogout, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspUserLogout(this, gcnew RspUserLogoutArgs(pUserLogout, pRspInfo, nRequestID, bIsLast));
	}

	void MdSpi::OnRspUserLogout(MdSpi^ sender, RspUserLogoutArgs^ e)
	{
		this->RspUserLogout(sender, e);
	}

	void MdSpi::OnRspQryMulticastInstrument(MulticastInstrumentField^ pMulticastInstrument, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryMulticastInstrument(this, gcnew RspQryMulticastInstrumentArgs(pMulticastInstrument, pRspInfo, nRequestID, bIsLast));
	}

	void MdSpi::OnRspQryMulticastInstrument(MdSpi^ sender, RspQryMulticastInstrumentArgs^ e)
	{
		this->RspQryMulticastInstrument(sender, e);
	}

	void MdSpi::OnRspError(RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspError(this, gcnew RspErrorArgs(pRspInfo, nRequestID, bIsLast));
	}

	void MdSpi::OnRspError(MdSpi^ sender, RspErrorArgs^ e)
	{
		this->RspError(sender, e);
	}

	void MdSpi::OnRspSubMarketData(SpecificInstrumentField^ pSpecificInstrument, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspSubMarketData(this, gcnew SpecificInstrumentEventArgs(pSpecificInstrument, pRspInfo, nRequestID, bIsLast));
	}

	void MdSpi::OnRspSubMarketData(MdSpi^ sender, SpecificInstrumentEventArgs^ e)
	{
		this->RspSubMarketData(sender, e);
	}

	void MdSpi::OnRspUnSubMarketData(SpecificInstrumentField^ pSpecificInstrument, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspUnSubMarketData(this, gcnew SpecificInstrumentEventArgs(pSpecificInstrument, pRspInfo, nRequestID, bIsLast));
	}

	void MdSpi::OnRspUnSubMarketData(MdSpi^ sender, SpecificInstrumentEventArgs^ e)
	{
		this->RspUnSubMarketData(sender, e);
	}

	void MdSpi::OnRspSubForQuoteRsp(SpecificInstrumentField^ pSpecificInstrument, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspSubForQuoteRsp(this, gcnew SpecificInstrumentEventArgs(pSpecificInstrument, pRspInfo, nRequestID, bIsLast));
	}

	void MdSpi::OnRspSubForQuoteRsp(MdSpi^ sender, SpecificInstrumentEventArgs^ e)
	{
		this->RspSubForQuoteRsp(sender, e);
	}

	void MdSpi::OnRspUnSubForQuoteRsp(SpecificInstrumentField^ pSpecificInstrument, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspUnSubForQuoteRsp(this, gcnew SpecificInstrumentEventArgs(pSpecificInstrument, pRspInfo, nRequestID, bIsLast));
	}

	void MdSpi::OnRspUnSubForQuoteRsp(MdSpi^ sender, SpecificInstrumentEventArgs^ e)
	{
		this->RspUnSubForQuoteRsp(sender, e);
	}

	void MdSpi::OnRtnDepthMarketData(DepthMarketDataField^ pDepthMarketData)
	{
		this->RtnDepthMarketData(this, gcnew RtnDepthMarketDataArgs(pDepthMarketData));
	}

	void MdSpi::OnRtnDepthMarketData(MdSpi^ sender, RtnDepthMarketDataArgs^ e)
	{
		this->RtnDepthMarketData(sender, e);
	}

	void MdSpi::OnRtnForQuoteRsp(ForQuoteRspField^ pForQuoteRsp)
	{
		this->RtnForQuoteRsp(this, gcnew RtnForQuoteRspArgs(pForQuoteRsp));
	}

	void MdSpi::OnRtnForQuoteRsp(MdSpi^ sender, RtnForQuoteRspArgs^ e)
	{
		this->RtnForQuoteRsp(sender, e);
	}
}
