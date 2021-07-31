#include "pch.h"
#include "TraderApi.h"

namespace PhoenixCTP
{
	void TraderApi::SetSpi(TraderSpi^ pSpi)
	{
		this->Spi = pSpi;
	}

	CThostFtdcTraderApi* TraderApi::CreateFtdcTraderApi(System::String^ pszFlowPath)
	{
		const char* pszFlowPathChar = netString2ConstChar(pszFlowPath);
		return CThostFtdcTraderApi::CreateFtdcTraderApi(pszFlowPathChar);
	}

	System::String^ TraderApi::GetApiVersion()
	{
		const char* version = CThostFtdcTraderApi::GetApiVersion();
		return gcnew System::String(version);
	}

	void TraderApi::Release()
	{
		this->CApi->Release();
	}

	void TraderApi::Init()
	{
		this->CApi->Init();
	}

	int TraderApi::Join()
	{
		return this->CApi->Join();
	}

	System::String^ TraderApi::GetTradingDay()
	{
		const char* tradingDay =  this->CApi->GetTradingDay();
		return gcnew System::String(tradingDay);
	}

	void TraderApi::RegisterFront(System::String^ pszFrontAddress)
	{
		this->CApi->RegisterFront(netString2Char(pszFrontAddress));
	}

	void TraderApi::RegisterNameServer(System::String^ pszNsAddress)
	{
		this->CApi->RegisterNameServer(netString2Char(pszNsAddress));
	}

	void TraderApi::RegisterFensUserInfo(FensUserInfoField^ pFensUserInfo)
	{
		this->CApi->RegisterFensUserInfo(pFensUserInfo->getUnmanagedStructP());
	}

	void TraderApi::RegisterSpi(TraderSpi^ pSpi)
	{
		if (pSpi->Api != this)
			pSpi->SetApi(this);
		this->SetSpi(pSpi);
		this->CApi->RegisterSpi(pSpi->pCSpi);
	}

	void TraderApi::SubscribePrivateTopic(THOST_TE_RESUME_TYPE nResumeType)
	{
		return this->CApi->SubscribePrivateTopic(nResumeType);
	}

	void TraderApi::SubscribePublicTopic(THOST_TE_RESUME_TYPE nResumeType)
	{
		return this->CApi->SubscribePublicTopic(nResumeType);
	}

	int TraderApi::ReqAuthenticate(ReqAuthenticateField^ pReqAuthenticateField, int nRequestID)
	{
		return this->CApi->ReqAuthenticate(pReqAuthenticateField->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::RegisterUserSystemInfo(UserSystemInfoField^ pUserSystemInfo)
	{
		return this->CApi->RegisterUserSystemInfo(pUserSystemInfo->getUnmanagedStructP());
	}

	int TraderApi::SubmitUserSystemInfo(UserSystemInfoField^ pUserSystemInfo)
	{
		return this->CApi->SubmitUserSystemInfo(pUserSystemInfo->getUnmanagedStructP());
	}

	int TraderApi::ReqUserLogin(ReqUserLoginField^ pReqUserLoginField, int nRequestID)
	{
		return this->CApi->ReqUserLogin(pReqUserLoginField->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqUserLogout(UserLogoutField^ pUserLogout, int nRequestID)
	{
		return this->CApi->ReqUserLogout(pUserLogout->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqUserPasswordUpdate(UserPasswordUpdateField^ pUserPasswordUpdate, int nRequestID)
	{
		return this->CApi->ReqUserPasswordUpdate(pUserPasswordUpdate->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqTradingAccountPasswordUpdate(TradingAccountPasswordUpdateField^ pTradingAccountPasswordUpdate, int nRequestID)
	{
		return this->CApi->ReqTradingAccountPasswordUpdate(pTradingAccountPasswordUpdate->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqUserAuthMethod(ReqUserAuthMethodField^ pReqUserAuthMethod, int nRequestID)
	{
		return this->CApi->ReqUserAuthMethod(pReqUserAuthMethod->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqGenUserCaptcha(ReqGenUserCaptchaField^ pReqGenUserCaptcha, int nRequestID)
	{
		return this->CApi->ReqGenUserCaptcha(pReqGenUserCaptcha->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqGenUserText(ReqGenUserTextField^ pReqGenUserText, int nRequestID)
	{
		return this->CApi->ReqGenUserText(pReqGenUserText->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqUserLoginWithCaptcha(ReqUserLoginWithCaptchaField^ pReqUserLoginWithCaptcha, int nRequestID)
	{
		return this->CApi->ReqUserLoginWithCaptcha(pReqUserLoginWithCaptcha->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqUserLoginWithText(ReqUserLoginWithTextField^ pReqUserLoginWithText, int nRequestID)
	{
		return this->CApi->ReqUserLoginWithText(pReqUserLoginWithText->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqUserLoginWithOTP(ReqUserLoginWithOTPField^ pReqUserLoginWithOTP, int nRequestID)
	{
		return this->CApi->ReqUserLoginWithOTP(pReqUserLoginWithOTP->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqOrderInsert(InputOrderField^ pInputOrder, int nRequestID)
	{
		return this->CApi->ReqOrderInsert(pInputOrder->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqParkedOrderInsert(ParkedOrderField^ pParkedOrder, int nRequestID)
	{
		return this->CApi->ReqParkedOrderInsert(pParkedOrder->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqParkedOrderAction(ParkedOrderActionField^ pParkedOrderAction, int nRequestID)
	{
		return this->CApi->ReqParkedOrderAction(pParkedOrderAction->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqOrderAction(InputOrderActionField^ pInputOrderAction, int nRequestID)
	{
		return this->CApi->ReqOrderAction(pInputOrderAction->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQryMaxOrderVolume(QryMaxOrderVolumeField^ pQryMaxOrderVolume, int nRequestID)
	{
		return this->CApi->ReqQryMaxOrderVolume(pQryMaxOrderVolume->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqSettlementInfoConfirm(SettlementInfoConfirmField^ pSettlementInfoConfirm, int nRequestID)
	{
		return this->CApi->ReqSettlementInfoConfirm(pSettlementInfoConfirm->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqRemoveParkedOrder(RemoveParkedOrderField^ pRemoveParkedOrder, int nRequestID)
	{
		return this->CApi->ReqRemoveParkedOrder(pRemoveParkedOrder->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqRemoveParkedOrderAction(RemoveParkedOrderActionField^ pRemoveParkedOrderAction, int nRequestID)
	{
		return this->CApi->ReqRemoveParkedOrderAction(pRemoveParkedOrderAction->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqExecOrderInsert(InputExecOrderField^ pInputExecOrder, int nRequestID)
	{
		return this->CApi->ReqExecOrderInsert(pInputExecOrder->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqExecOrderAction(InputExecOrderActionField^ pInputExecOrderAction, int nRequestID)
	{
		return this->CApi->ReqExecOrderAction(pInputExecOrderAction->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqForQuoteInsert(InputForQuoteField^ pInputForQuote, int nRequestID)
	{
		return this->CApi->ReqForQuoteInsert(pInputForQuote->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQuoteInsert(InputQuoteField^ pInputQuote, int nRequestID)
	{
		return this->CApi->ReqQuoteInsert(pInputQuote->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQuoteAction(InputQuoteActionField^ pInputQuoteAction, int nRequestID)
	{
		return this->CApi->ReqQuoteAction(pInputQuoteAction->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqBatchOrderAction(InputBatchOrderActionField^ pInputBatchOrderAction, int nRequestID)
	{
		return this->CApi->ReqBatchOrderAction(pInputBatchOrderAction->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqOptionSelfCloseInsert(InputOptionSelfCloseField^ pInputOptionSelfClose, int nRequestID)
	{
		return this->CApi->ReqOptionSelfCloseInsert(pInputOptionSelfClose->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqOptionSelfCloseAction(InputOptionSelfCloseActionField^ pInputOptionSelfCloseAction, int nRequestID)
	{
		return this->CApi->ReqOptionSelfCloseAction(pInputOptionSelfCloseAction->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqCombActionInsert(InputCombActionField^ pInputCombAction, int nRequestID)
	{
		return this->CApi->ReqCombActionInsert(pInputCombAction->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQryOrder(QryOrderField^ pQryOrder, int nRequestID)
	{
		return this->CApi->ReqQryOrder(pQryOrder->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQryTrade(QryTradeField^ pQryTrade, int nRequestID)
	{
		return this->CApi->ReqQryTrade(pQryTrade->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQryInvestorPosition(QryInvestorPositionField^ pQryInvestorPosition, int nRequestID)
	{
		return this->CApi->ReqQryInvestorPosition(pQryInvestorPosition->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQryTradingAccount(QryTradingAccountField^ pQryTradingAccount, int nRequestID)
	{
		return this->CApi->ReqQryTradingAccount(pQryTradingAccount->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQryInvestor(QryInvestorField^ pQryInvestor, int nRequestID)
	{
		return this->CApi->ReqQryInvestor(pQryInvestor->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQryTradingCode(QryTradingCodeField^ pQryTradingCode, int nRequestID)
	{
		return this->CApi->ReqQryTradingCode(pQryTradingCode->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQryInstrumentMarginRate(QryInstrumentMarginRateField^ pQryInstrumentMarginRate, int nRequestID)
	{
		return this->CApi->ReqQryInstrumentMarginRate(pQryInstrumentMarginRate->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQryInstrumentCommissionRate(QryInstrumentCommissionRateField^ pQryInstrumentCommissionRate, int nRequestID)
	{
		return this->CApi->ReqQryInstrumentCommissionRate(pQryInstrumentCommissionRate->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQryExchange(QryExchangeField^ pQryExchange, int nRequestID)
	{
		return this->CApi->ReqQryExchange(pQryExchange->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQryProduct(QryProductField^ pQryProduct, int nRequestID)
	{
		return this->CApi->ReqQryProduct(pQryProduct->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQryInstrument(QryInstrumentField^ pQryInstrument, int nRequestID)
	{
		return this->CApi->ReqQryInstrument(pQryInstrument->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQryDepthMarketData(QryDepthMarketDataField^ pQryDepthMarketData, int nRequestID)
	{
		return this->CApi->ReqQryDepthMarketData(pQryDepthMarketData->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQrySettlementInfo(QrySettlementInfoField^ pQrySettlementInfo, int nRequestID)
	{
		return this->CApi->ReqQrySettlementInfo(pQrySettlementInfo->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQryTransferBank(QryTransferBankField^ pQryTransferBank, int nRequestID)
	{
		return this->CApi->ReqQryTransferBank(pQryTransferBank->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQryInvestorPositionDetail(QryInvestorPositionDetailField^ pQryInvestorPositionDetail, int nRequestID)
	{
		return this->CApi->ReqQryInvestorPositionDetail(pQryInvestorPositionDetail->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQryNotice(QryNoticeField^ pQryNotice, int nRequestID)
	{
		return this->CApi->ReqQryNotice(pQryNotice->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQrySettlementInfoConfirm(QrySettlementInfoConfirmField^ pQrySettlementInfoConfirm, int nRequestID)
	{
		return this->CApi->ReqQrySettlementInfoConfirm(pQrySettlementInfoConfirm->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQryInvestorPositionCombineDetail(QryInvestorPositionCombineDetailField^ pQryInvestorPositionCombineDetail, int nRequestID)
	{
		return this->CApi->ReqQryInvestorPositionCombineDetail(pQryInvestorPositionCombineDetail->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQryCFMMCTradingAccountKey(QryCFMMCTradingAccountKeyField^ pQryCFMMCTradingAccountKey, int nRequestID)
	{
		return this->CApi->ReqQryCFMMCTradingAccountKey(pQryCFMMCTradingAccountKey->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQryEWarrantOffset(QryEWarrantOffsetField^ pQryEWarrantOffset, int nRequestID)
	{
		return this->CApi->ReqQryEWarrantOffset(pQryEWarrantOffset->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQryInvestorProductGroupMargin(QryInvestorProductGroupMarginField^ pQryInvestorProductGroupMargin, int nRequestID)
	{
		return this->CApi->ReqQryInvestorProductGroupMargin(pQryInvestorProductGroupMargin->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQryExchangeMarginRate(QryExchangeMarginRateField^ pQryExchangeMarginRate, int nRequestID)
	{
		return this->CApi->ReqQryExchangeMarginRate(pQryExchangeMarginRate->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQryExchangeMarginRateAdjust(QryExchangeMarginRateAdjustField^ pQryExchangeMarginRateAdjust, int nRequestID)
	{
		return this->CApi->ReqQryExchangeMarginRateAdjust(pQryExchangeMarginRateAdjust->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQryExchangeRate(QryExchangeRateField^ pQryExchangeRate, int nRequestID)
	{
		return this->CApi->ReqQryExchangeRate(pQryExchangeRate->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQrySecAgentACIDMap(QrySecAgentACIDMapField^ pQrySecAgentACIDMap, int nRequestID)
	{
		return this->CApi->ReqQrySecAgentACIDMap(pQrySecAgentACIDMap->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQryProductExchRate(QryProductExchRateField^ pQryProductExchRate, int nRequestID)
	{
		return this->CApi->ReqQryProductExchRate(pQryProductExchRate->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQryProductGroup(QryProductGroupField^ pQryProductGroup, int nRequestID)
	{
		return this->CApi->ReqQryProductGroup(pQryProductGroup->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQryMMInstrumentCommissionRate(QryMMInstrumentCommissionRateField^ pQryMMInstrumentCommissionRate, int nRequestID)
	{
		return this->CApi->ReqQryMMInstrumentCommissionRate(pQryMMInstrumentCommissionRate->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQryMMOptionInstrCommRate(QryMMOptionInstrCommRateField^ pQryMMOptionInstrCommRate, int nRequestID)
	{
		return this->CApi->ReqQryMMOptionInstrCommRate(pQryMMOptionInstrCommRate->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQryInstrumentOrderCommRate(QryInstrumentOrderCommRateField^ pQryInstrumentOrderCommRate, int nRequestID)
	{
		return this->CApi->ReqQryInstrumentOrderCommRate(pQryInstrumentOrderCommRate->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQrySecAgentTradingAccount(QryTradingAccountField^ pQryTradingAccount, int nRequestID)
	{
		return this->CApi->ReqQrySecAgentTradingAccount(pQryTradingAccount->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQrySecAgentCheckMode(QrySecAgentCheckModeField^ pQrySecAgentCheckMode, int nRequestID)
	{
		return this->CApi->ReqQrySecAgentCheckMode(pQrySecAgentCheckMode->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQrySecAgentTradeInfo(QrySecAgentTradeInfoField^ pQrySecAgentTradeInfo, int nRequestID)
	{
		return this->CApi->ReqQrySecAgentTradeInfo(pQrySecAgentTradeInfo->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQryOptionInstrTradeCost(QryOptionInstrTradeCostField^ pQryOptionInstrTradeCost, int nRequestID)
	{
		return this->CApi->ReqQryOptionInstrTradeCost(pQryOptionInstrTradeCost->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQryOptionInstrCommRate(QryOptionInstrCommRateField^ pQryOptionInstrCommRate, int nRequestID)
	{
		return this->CApi->ReqQryOptionInstrCommRate(pQryOptionInstrCommRate->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQryExecOrder(QryExecOrderField^ pQryExecOrder, int nRequestID)
	{
		return this->CApi->ReqQryExecOrder(pQryExecOrder->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQryForQuote(QryForQuoteField^ pQryForQuote, int nRequestID)
	{
		return this->CApi->ReqQryForQuote(pQryForQuote->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQryQuote(QryQuoteField^ pQryQuote, int nRequestID)
	{
		return this->CApi->ReqQryQuote(pQryQuote->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQryOptionSelfClose(QryOptionSelfCloseField^ pQryOptionSelfClose, int nRequestID)
	{
		return this->CApi->ReqQryOptionSelfClose(pQryOptionSelfClose->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQryInvestUnit(QryInvestUnitField^ pQryInvestUnit, int nRequestID)
	{
		return this->CApi->ReqQryInvestUnit(pQryInvestUnit->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQryCombInstrumentGuard(QryCombInstrumentGuardField^ pQryCombInstrumentGuard, int nRequestID)
	{
		return this->CApi->ReqQryCombInstrumentGuard(pQryCombInstrumentGuard->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQryCombAction(QryCombActionField^ pQryCombAction, int nRequestID)
	{
		return this->CApi->ReqQryCombAction(pQryCombAction->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQryTransferSerial(QryTransferSerialField^ pQryTransferSerial, int nRequestID)
	{
		return this->CApi->ReqQryTransferSerial(pQryTransferSerial->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQryAccountregister(QryAccountregisterField^ pQryAccountregister, int nRequestID)
	{
		return this->CApi->ReqQryAccountregister(pQryAccountregister->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQryContractBank(QryContractBankField^ pQryContractBank, int nRequestID)
	{
		return this->CApi->ReqQryContractBank(pQryContractBank->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQryParkedOrder(QryParkedOrderField^ pQryParkedOrder, int nRequestID)
	{
		return this->CApi->ReqQryParkedOrder(pQryParkedOrder->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQryParkedOrderAction(QryParkedOrderActionField^ pQryParkedOrderAction, int nRequestID)
	{
		return this->CApi->ReqQryParkedOrderAction(pQryParkedOrderAction->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQryTradingNotice(QryTradingNoticeField^ pQryTradingNotice, int nRequestID)
	{
		return this->CApi->ReqQryTradingNotice(pQryTradingNotice->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQryBrokerTradingParams(QryBrokerTradingParamsField^ pQryBrokerTradingParams, int nRequestID)
	{
		return this->CApi->ReqQryBrokerTradingParams(pQryBrokerTradingParams->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQryBrokerTradingAlgos(QryBrokerTradingAlgosField^ pQryBrokerTradingAlgos, int nRequestID)
	{
		return this->CApi->ReqQryBrokerTradingAlgos(pQryBrokerTradingAlgos->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQueryCFMMCTradingAccountToken(QueryCFMMCTradingAccountTokenField^ pQueryCFMMCTradingAccountToken, int nRequestID)
	{
		return this->CApi->ReqQueryCFMMCTradingAccountToken(pQueryCFMMCTradingAccountToken->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqFromBankToFutureByFuture(ReqTransferField^ pReqTransfer, int nRequestID)
	{
		return this->CApi->ReqFromBankToFutureByFuture(pReqTransfer->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqFromFutureToBankByFuture(ReqTransferField^ pReqTransfer, int nRequestID)
	{
		return this->CApi->ReqFromFutureToBankByFuture(pReqTransfer->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQueryBankAccountMoneyByFuture(ReqQueryAccountField^ pReqQueryAccount, int nRequestID)
	{
		return this->CApi->ReqQueryBankAccountMoneyByFuture(pReqQueryAccount->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQryClassifiedInstrument(QryClassifiedInstrumentField^ pQryClassifiedInstrument, int nRequestID)
	{
		return this->CApi->ReqQryClassifiedInstrument(pQryClassifiedInstrument->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQryCombPromotionParam(QryCombPromotionParamField^ pQryCombPromotionParam, int nRequestID)
	{
		return this->CApi->ReqQryCombPromotionParam(pQryCombPromotionParam->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQryRiskSettleInvstPosition(QryRiskSettleInvstPositionField^ pQryRiskSettleInvstPosition, int nRequestID)
	{
		return this->CApi->ReqQryRiskSettleInvstPosition(pQryRiskSettleInvstPosition->getUnmanagedStructP(), nRequestID);
	}

	int TraderApi::ReqQryRiskSettleProductStatus(QryRiskSettleProductStatusField^ pQryRiskSettleProductStatus, int nRequestID)
	{
		return this->CApi->ReqQryRiskSettleProductStatus(pQryRiskSettleProductStatus->getUnmanagedStructP(), nRequestID);
	}


}

