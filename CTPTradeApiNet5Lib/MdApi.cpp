#include "pch.h"
#include "MdApi.h"

#include <iostream>

namespace PhoenixCTP
{
	void MdApi::SetSpi(MdSpi^ Spi)
	{
		this->Spi = Spi;
	}

	CThostFtdcMdApi* MdApi::CreateFtdcMdApi(System::String^ pszFlowPath, const bool bIsUsingUdp, const bool bIsMulticast)
	{
		const char* pszFlowPathChar = netString2ConstChar(pszFlowPath);
		return CThostFtdcMdApi::CreateFtdcMdApi();
	}

	void MdApi::CreateMdApi(System::String^ pszFlowPath, const bool bIsUsingUdp, const bool bIsMulticast)
	{
		this->CApi = MdApi::CreateFtdcMdApi(pszFlowPath, bIsUsingUdp, bIsMulticast);
	}

	System::String^ MdApi::GetApiVersion()
	{
		const char* version = CThostFtdcMdApi::GetApiVersion();
		return gcnew System::String(version);
	}

	void MdApi::Release()
	{
		this->CApi->Release();
	}

	void MdApi::Init()
	{
		this->CApi->Init();
	}

	int MdApi::Join()
	{
		return this->CApi->Join();
	}

	System::String^ MdApi::GetTradingDay()
	{
		const char* tradingDay = this->CApi->GetTradingDay();
		return gcnew System::String(tradingDay);
	}

	void MdApi::RegisterFront(System::String^ pszFrontAddress)
	{
		this->CApi->RegisterFront(netString2Char(pszFrontAddress));
	}

	void MdApi::RegisterNameServer(System::String^ pszNsAddress)
	{
		this->CApi->RegisterNameServer(netString2Char(pszNsAddress));
	}

	void MdApi::RegisterFensUserInfo(FensUserInfoField^ pFensUserInfo)
	{
		this->CApi->RegisterFensUserInfo(pFensUserInfo->getUnmanagedStructP());
	}

	void MdApi::RegisterSpi(MdSpi^ pSpi)
	{
		if (pSpi->Api != this)
			pSpi->SetApi(this);
		this->SetSpi(pSpi);
		this->CApi->RegisterSpi(pSpi->pCSpi);
	}

	int MdApi::SubscribeMarketData(array<System::String^>^ ppInstrumentID, int nCount)
	{
		return this->CApi->SubscribeMarketData(netArray2CharArray(ppInstrumentID), nCount);
	}

	int MdApi::UnSubscribeMarketData(array<System::String^>^ ppInstrumentID, int nCount)
	{
		return this->CApi->UnSubscribeMarketData(netArray2CharArray(ppInstrumentID), nCount);
	}

	int MdApi::SubscribeForQuoteRsp(array<System::String^>^ ppInstrumentID, int nCount)
	{
		return this->CApi->SubscribeForQuoteRsp(netArray2CharArray(ppInstrumentID), nCount);
	}

	int MdApi::UnSubscribeForQuoteRsp(array<System::String^>^ ppInstrumentID, int nCount)
	{
		return this->CApi->UnSubscribeForQuoteRsp(netArray2CharArray(ppInstrumentID), nCount);
	}

	int MdApi::ReqUserLogin(ReqUserLoginField^ pReqUserLoginField, int nRequestID)
	{
		CThostFtdcReqUserLoginField* unmanagedLogin = pReqUserLoginField->getUnmanagedStructP();
		return this->CApi->ReqUserLogin(pReqUserLoginField->getUnmanagedStructP(), nRequestID);
	}

	int MdApi::ReqUserLogout(UserLogoutField^ pUserLogout, int nReqstID)
	{
		return this->CApi->ReqUserLogout(pUserLogout->getUnmanagedStructP(), nReqstID);
	}

	int MdApi::ReqQryMulticastInstrument(QryMulticastInstrumentField^ pQryMulticastInstrumentField, int nRequestID)
	{
		return this->CApi->ReqQryMulticastInstrument(pQryMulticastInstrumentField->getUnmanagedStructP(), nRequestID);
	}

	MdApi::~MdApi()
	{
		this->Release();
	}
}
