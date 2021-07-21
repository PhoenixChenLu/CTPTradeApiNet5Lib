#include "pch.h"
#include "MdApi.h"

namespace PhoenixCTP
{
	CThostFtdcMdApi* MdApi::CreateFtdcMdApi(System::String^ pszFlowPath, const bool bIsUsingUdp, const bool bIsMulticast)
	{
		const char* pszFlowPathChar = netString2ConstChar(pszFlowPath);
		return CThostFtdcMdApi::CreateFtdcMdApi(pszFlowPathChar, bIsUsingUdp, bIsMulticast);
	}

	void MdApi::CreateMdApi(System::String^ pszFlowPath, const bool bIsUsingUdp, const bool bIsMulticast)
	{
		this->api = MdApi::CreateFtdcMdApi(pszFlowPath, bIsUsingUdp, bIsMulticast);
	}

	System::String^ MdApi::GetApiVersion()
	{
		const char* version = CThostFtdcMdApi::GetApiVersion();
		return gcnew System::String(version);
	}

	void MdApi::Release()
	{
		this->api->Release();
	}

	void MdApi::Init()
	{
		this->api->Init();
	}

	int MdApi::Join()
	{
		return this->api->Join();
	}

	System::String^ MdApi::GetTradingDay()
	{
		const char* tradingDay = this->api->GetTradingDay();
		return gcnew System::String(tradingDay);
	}

	void MdApi::RegisterFront(System::String^ pszFrontAddress)
	{
		this->api->RegisterFront(netString2Char(pszFrontAddress));
	}

	void MdApi::RegisterNameServer(System::String^ pszNsAddress)
	{
		this->api->RegisterNameServer(netString2Char(pszNsAddress));
	}

	void MdApi::RegisterFensUserInfo(FensUserInfoField^ pFensUserInfo)
	{
		this->api->RegisterFensUserInfo(pFensUserInfo->getUnmanagedStructP());
	}

	void MdApi::RegisterSpi(MdSpi^ pSpi)
	{
		this->api->RegisterSpi(pSpi->spi);
	}

	int MdApi::SubscribeMarketData(array<System::String^>^ ppInstrumentID, int nCount)
	{
		return this->api->SubscribeMarketData(netArray2CharArray(ppInstrumentID), nCount);
	}

	int MdApi::UnSubscribeMarketData(array<System::String^>^ ppInstrumentID, int nCount)
	{
		return this->api->UnSubscribeMarketData(netArray2CharArray(ppInstrumentID), nCount);
	}

	int MdApi::SubscribeForQuoteRsp(array<System::String^>^ ppInstrumentID, int nCount)
	{
		return this->api->SubscribeForQuoteRsp(netArray2CharArray(ppInstrumentID), nCount);
	}

	int MdApi::UnSubscribeForQuoteRsp(array<System::String^>^ ppInstrumentID, int nCount)
	{
		return this->api->UnSubscribeForQuoteRsp(netArray2CharArray(ppInstrumentID), nCount);
	}

	MdApi::~MdApi()
	{
		this->Release();
	}
}
