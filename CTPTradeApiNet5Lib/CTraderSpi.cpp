#include "pch.h"
#include "CTraderSpi.h"
#include "TraderSpi.h"


namespace PhoenixCTP
{
	CTraderSpi::CTraderSpi(System::IntPtr intPTraderSpi)
	{
		this->pTraderSpi = intPTraderSpi;
	}

	void CTraderSpi::setNetSpi(System::IntPtr intPTraderSpi)
	{
		this->pTraderSpi = intPTraderSpi;
	}

	void CTraderSpi::OnFrontConnected()
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnFrontConnected();
	}

	void CTraderSpi::OnFrontDisconnected(int nReason)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnFrontDisconnected(nReason);
	}

	void CTraderSpi::OnHeartBeatWarning(int nTimeLapse)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnHeartBeatWarning(nTimeLapse);
	}

	void CTraderSpi::OnRspAuthenticate(CThostFtdcRspAuthenticateField* pRspAuthenticateField, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspAuthenticate(gcnew RspAuthenticateField(pRspAuthenticateField), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspUserLogin(CThostFtdcRspUserLoginField* pRspUserLogin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspUserLogin(gcnew RspUserLoginField(pRspUserLogin), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspUserLogout(CThostFtdcUserLogoutField* pUserLogout, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspUserLogout(gcnew UserLogoutField(pUserLogout), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField* pUserPasswordUpdate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspUserPasswordUpdate(gcnew UserPasswordUpdateField(pUserPasswordUpdate), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField* pTradingAccountPasswordUpdate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspTradingAccountPasswordUpdate(gcnew TradingAccountPasswordUpdateField(pTradingAccountPasswordUpdate), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspUserAuthMethod(CThostFtdcRspUserAuthMethodField* pRspUserAuthMethod, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspUserAuthMethod(gcnew RspUserAuthMethodField(pRspUserAuthMethod), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspGenUserCaptcha(CThostFtdcRspGenUserCaptchaField* pRspGenUserCaptcha, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspGenUserCaptcha(gcnew RspGenUserCaptchaField(pRspGenUserCaptcha), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspGenUserText(CThostFtdcRspGenUserTextField* pRspGenUserText, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspGenUserText(gcnew RspGenUserTextField(pRspGenUserText), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspOrderInsert(CThostFtdcInputOrderField* pInputOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspOrderInsert(gcnew InputOrderField(pInputOrder), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspParkedOrderInsert(CThostFtdcParkedOrderField* pParkedOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspParkedOrderInsert(gcnew ParkedOrderField(pParkedOrder), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspParkedOrderAction(CThostFtdcParkedOrderActionField* pParkedOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspParkedOrderAction(gcnew ParkedOrderActionField(pParkedOrderAction), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspOrderAction(CThostFtdcInputOrderActionField* pInputOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspOrderAction(gcnew InputOrderActionField(pInputOrderAction), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQryMaxOrderVolume(CThostFtdcQryMaxOrderVolumeField* pQryMaxOrderVolume, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQryMaxOrderVolume(gcnew QryMaxOrderVolumeField(pQryMaxOrderVolume), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField* pSettlementInfoConfirm, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspSettlementInfoConfirm(gcnew SettlementInfoConfirmField(pSettlementInfoConfirm), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderField* pRemoveParkedOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspRemoveParkedOrder(gcnew RemoveParkedOrderField(pRemoveParkedOrder), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField* pRemoveParkedOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspRemoveParkedOrderAction(gcnew RemoveParkedOrderActionField(pRemoveParkedOrderAction), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspExecOrderInsert(CThostFtdcInputExecOrderField* pInputExecOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspExecOrderInsert(gcnew InputExecOrderField(pInputExecOrder), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspExecOrderAction(CThostFtdcInputExecOrderActionField* pInputExecOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspExecOrderAction(gcnew InputExecOrderActionField(pInputExecOrderAction), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspForQuoteInsert(CThostFtdcInputForQuoteField* pInputForQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspForQuoteInsert(gcnew InputForQuoteField(pInputForQuote), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQuoteInsert(CThostFtdcInputQuoteField* pInputQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQuoteInsert(gcnew InputQuoteField(pInputQuote), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQuoteAction(CThostFtdcInputQuoteActionField* pInputQuoteAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQuoteAction(gcnew InputQuoteActionField(pInputQuoteAction), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspBatchOrderAction(CThostFtdcInputBatchOrderActionField* pInputBatchOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspBatchOrderAction(gcnew InputBatchOrderActionField(pInputBatchOrderAction), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField* pInputOptionSelfClose, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspOptionSelfCloseInsert(gcnew InputOptionSelfCloseField(pInputOptionSelfClose), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspOptionSelfCloseAction(CThostFtdcInputOptionSelfCloseActionField* pInputOptionSelfCloseAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspOptionSelfCloseAction(gcnew InputOptionSelfCloseActionField(pInputOptionSelfCloseAction), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspCombActionInsert(CThostFtdcInputCombActionField* pInputCombAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspCombActionInsert(gcnew InputCombActionField(pInputCombAction), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQryOrder(CThostFtdcOrderField* pOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQryOrder(gcnew OrderField(pOrder), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQryTrade(CThostFtdcTradeField* pTrade, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQryTrade(gcnew TradeField(pTrade), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQryInvestorPosition(CThostFtdcInvestorPositionField* pInvestorPosition, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQryInvestorPosition(gcnew InvestorPositionField(pInvestorPosition), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQryTradingAccount(CThostFtdcTradingAccountField* pTradingAccount, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQryTradingAccount(gcnew TradingAccountField(pTradingAccount), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQryInvestor(CThostFtdcInvestorField* pInvestor, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQryInvestor(gcnew InvestorField(pInvestor), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQryTradingCode(CThostFtdcTradingCodeField* pTradingCode, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQryTradingCode(gcnew TradingCodeField(pTradingCode), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField* pInstrumentMarginRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQryInstrumentMarginRate(gcnew InstrumentMarginRateField(pInstrumentMarginRate), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField* pInstrumentCommissionRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQryInstrumentCommissionRate(gcnew InstrumentCommissionRateField(pInstrumentCommissionRate), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQryExchange(CThostFtdcExchangeField* pExchange, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQryExchange(gcnew ExchangeField(pExchange), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQryProduct(CThostFtdcProductField* pProduct, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQryProduct(gcnew ProductField(pProduct), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQryInstrument(CThostFtdcInstrumentField* pInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQryInstrument(gcnew InstrumentField(pInstrument), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField* pDepthMarketData, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQryDepthMarketData(gcnew DepthMarketDataField(pDepthMarketData), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQrySettlementInfo(CThostFtdcSettlementInfoField* pSettlementInfo, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQrySettlementInfo(gcnew SettlementInfoField(pSettlementInfo), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQryTransferBank(CThostFtdcTransferBankField* pTransferBank, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQryTransferBank(gcnew TransferBankField(pTransferBank), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField* pInvestorPositionDetail, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQryInvestorPositionDetail(gcnew InvestorPositionDetailField(pInvestorPositionDetail), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQryNotice(CThostFtdcNoticeField* pNotice, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQryNotice(gcnew NoticeField(pNotice), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField* pSettlementInfoConfirm, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQrySettlementInfoConfirm(gcnew SettlementInfoConfirmField(pSettlementInfoConfirm), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField* pInvestorPositionCombineDetail, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQryInvestorPositionCombineDetail(gcnew InvestorPositionCombineDetailField(pInvestorPositionCombineDetail), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQryCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyField* pCFMMCTradingAccountKey, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQryCFMMCTradingAccountKey(gcnew CFMMCTradingAccountKeyField(pCFMMCTradingAccountKey), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQryEWarrantOffset(CThostFtdcEWarrantOffsetField* pEWarrantOffset, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQryEWarrantOffset(gcnew EWarrantOffsetField(pEWarrantOffset), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQryInvestorProductGroupMargin(CThostFtdcInvestorProductGroupMarginField* pInvestorProductGroupMargin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQryInvestorProductGroupMargin(gcnew InvestorProductGroupMarginField(pInvestorProductGroupMargin), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQryExchangeMarginRate(CThostFtdcExchangeMarginRateField* pExchangeMarginRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQryExchangeMarginRate(gcnew ExchangeMarginRateField(pExchangeMarginRate), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQryExchangeMarginRateAdjust(CThostFtdcExchangeMarginRateAdjustField* pExchangeMarginRateAdjust, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQryExchangeMarginRateAdjust(gcnew ExchangeMarginRateAdjustField(pExchangeMarginRateAdjust), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQryExchangeRate(CThostFtdcExchangeRateField* pExchangeRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQryExchangeRate(gcnew ExchangeRateField(pExchangeRate), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQrySecAgentACIDMap(CThostFtdcSecAgentACIDMapField* pSecAgentACIDMap, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQrySecAgentACIDMap(gcnew SecAgentACIDMapField(pSecAgentACIDMap), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQryProductExchRate(CThostFtdcProductExchRateField* pProductExchRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQryProductExchRate(gcnew ProductExchRateField(pProductExchRate), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQryProductGroup(CThostFtdcProductGroupField* pProductGroup, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQryProductGroup(gcnew ProductGroupField(pProductGroup), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQryMMInstrumentCommissionRate(CThostFtdcMMInstrumentCommissionRateField* pMMInstrumentCommissionRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQryMMInstrumentCommissionRate(gcnew MMInstrumentCommissionRateField(pMMInstrumentCommissionRate), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQryMMOptionInstrCommRate(CThostFtdcMMOptionInstrCommRateField* pMMOptionInstrCommRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQryMMOptionInstrCommRate(gcnew MMOptionInstrCommRateField(pMMOptionInstrCommRate), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQryInstrumentOrderCommRate(CThostFtdcInstrumentOrderCommRateField* pInstrumentOrderCommRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQryInstrumentOrderCommRate(gcnew InstrumentOrderCommRateField(pInstrumentOrderCommRate), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQrySecAgentTradingAccount(CThostFtdcTradingAccountField* pTradingAccount, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQrySecAgentTradingAccount(gcnew TradingAccountField(pTradingAccount), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQrySecAgentCheckMode(CThostFtdcSecAgentCheckModeField* pSecAgentCheckMode, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQrySecAgentCheckMode(gcnew SecAgentCheckModeField(pSecAgentCheckMode), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQrySecAgentTradeInfo(CThostFtdcSecAgentTradeInfoField* pSecAgentTradeInfo, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQrySecAgentTradeInfo(gcnew SecAgentTradeInfoField(pSecAgentTradeInfo), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQryOptionInstrTradeCost(CThostFtdcOptionInstrTradeCostField* pOptionInstrTradeCost, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQryOptionInstrTradeCost(gcnew OptionInstrTradeCostField(pOptionInstrTradeCost), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQryOptionInstrCommRate(CThostFtdcOptionInstrCommRateField* pOptionInstrCommRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQryOptionInstrCommRate(gcnew OptionInstrCommRateField(pOptionInstrCommRate), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQryExecOrder(CThostFtdcExecOrderField* pExecOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQryExecOrder(gcnew ExecOrderField(pExecOrder), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQryForQuote(CThostFtdcForQuoteField* pForQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQryForQuote(gcnew ForQuoteField(pForQuote), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQryQuote(CThostFtdcQuoteField* pQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQryQuote(gcnew QuoteField(pQuote), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQryOptionSelfClose(CThostFtdcOptionSelfCloseField* pOptionSelfClose, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQryOptionSelfClose(gcnew OptionSelfCloseField(pOptionSelfClose), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQryInvestUnit(CThostFtdcInvestUnitField* pInvestUnit, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQryInvestUnit(gcnew InvestUnitField(pInvestUnit), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQryCombInstrumentGuard(CThostFtdcCombInstrumentGuardField* pCombInstrumentGuard, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQryCombInstrumentGuard(gcnew CombInstrumentGuardField(pCombInstrumentGuard), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQryCombAction(CThostFtdcCombActionField* pCombAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQryCombAction(gcnew CombActionField(pCombAction), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQryTransferSerial(CThostFtdcTransferSerialField* pTransferSerial, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQryTransferSerial(gcnew TransferSerialField(pTransferSerial), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQryAccountregister(CThostFtdcAccountregisterField* pAccountregister, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQryAccountregister(gcnew AccountregisterField(pAccountregister), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspError(CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspError(gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRtnOrder(CThostFtdcOrderField* pOrder)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRtnOrder(gcnew OrderField(pOrder));
	}

	void CTraderSpi::OnRtnTrade(CThostFtdcTradeField* pTrade)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRtnTrade(gcnew TradeField(pTrade));
	}

	void CTraderSpi::OnErrRtnOrderInsert(CThostFtdcInputOrderField* pInputOrder, CThostFtdcRspInfoField* pRspInfo)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnErrRtnOrderInsert(gcnew InputOrderField(pInputOrder), gcnew RspInfoField(pRspInfo));
	}

	void CTraderSpi::OnErrRtnOrderAction(CThostFtdcOrderActionField* pOrderAction, CThostFtdcRspInfoField* pRspInfo)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnErrRtnOrderAction(gcnew OrderActionField(pOrderAction), gcnew RspInfoField(pRspInfo));
	}

	void CTraderSpi::OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField* pInstrumentStatus)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRtnInstrumentStatus(gcnew InstrumentStatusField(pInstrumentStatus));
	}

	void CTraderSpi::OnRtnBulletin(CThostFtdcBulletinField* pBulletin)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRtnBulletin(gcnew BulletinField(pBulletin));
	}

	void CTraderSpi::OnRtnTradingNotice(CThostFtdcTradingNoticeInfoField* pTradingNoticeInfo)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRtnTradingNotice(gcnew TradingNoticeInfoField(pTradingNoticeInfo));
	}

	void CTraderSpi::OnRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderField* pErrorConditionalOrder)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRtnErrorConditionalOrder(gcnew ErrorConditionalOrderField(pErrorConditionalOrder));
	}

	void CTraderSpi::OnRtnExecOrder(CThostFtdcExecOrderField* pExecOrder)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRtnExecOrder(gcnew ExecOrderField(pExecOrder));
	}

	void CTraderSpi::OnErrRtnExecOrderInsert(CThostFtdcInputExecOrderField* pInputExecOrder, CThostFtdcRspInfoField* pRspInfo)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnErrRtnExecOrderInsert(gcnew InputExecOrderField(pInputExecOrder), gcnew RspInfoField(pRspInfo));
	}

	void CTraderSpi::OnErrRtnExecOrderAction(CThostFtdcExecOrderActionField* pExecOrderAction, CThostFtdcRspInfoField* pRspInfo)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnErrRtnExecOrderAction(gcnew ExecOrderActionField(pExecOrderAction), gcnew RspInfoField(pRspInfo));
	}

	void CTraderSpi::OnErrRtnForQuoteInsert(CThostFtdcInputForQuoteField* pInputForQuote, CThostFtdcRspInfoField* pRspInfo)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnErrRtnForQuoteInsert(gcnew InputForQuoteField(pInputForQuote), gcnew RspInfoField(pRspInfo));
	}

	void CTraderSpi::OnRtnQuote(CThostFtdcQuoteField* pQuote)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRtnQuote(gcnew QuoteField(pQuote));
	}

	void CTraderSpi::OnErrRtnQuoteInsert(CThostFtdcInputQuoteField* pInputQuote, CThostFtdcRspInfoField* pRspInfo)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnErrRtnQuoteInsert(gcnew InputQuoteField(pInputQuote), gcnew RspInfoField(pRspInfo));
	}

	void CTraderSpi::OnErrRtnQuoteAction(CThostFtdcQuoteActionField* pQuoteAction, CThostFtdcRspInfoField* pRspInfo)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnErrRtnQuoteAction(gcnew QuoteActionField(pQuoteAction), gcnew RspInfoField(pRspInfo));
	}

	void CTraderSpi::OnRtnForQuoteRsp(CThostFtdcForQuoteRspField* pForQuoteRsp)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRtnForQuoteRsp(gcnew ForQuoteRspField(pForQuoteRsp));
	}

	void CTraderSpi::OnRtnCFMMCTradingAccountToken(CThostFtdcCFMMCTradingAccountTokenField* pCFMMCTradingAccountToken)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRtnCFMMCTradingAccountToken(gcnew CFMMCTradingAccountTokenField(pCFMMCTradingAccountToken));
	}

	void CTraderSpi::OnErrRtnBatchOrderAction(CThostFtdcBatchOrderActionField* pBatchOrderAction, CThostFtdcRspInfoField* pRspInfo)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnErrRtnBatchOrderAction(gcnew BatchOrderActionField(pBatchOrderAction), gcnew RspInfoField(pRspInfo));
	}

	void CTraderSpi::OnRtnOptionSelfClose(CThostFtdcOptionSelfCloseField* pOptionSelfClose)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRtnOptionSelfClose(gcnew OptionSelfCloseField(pOptionSelfClose));
	}

	void CTraderSpi::OnErrRtnOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField* pInputOptionSelfClose, CThostFtdcRspInfoField* pRspInfo)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnErrRtnOptionSelfCloseInsert(gcnew InputOptionSelfCloseField(pInputOptionSelfClose), gcnew RspInfoField(pRspInfo));
	}

	void CTraderSpi::OnErrRtnOptionSelfCloseAction(CThostFtdcOptionSelfCloseActionField* pOptionSelfCloseAction, CThostFtdcRspInfoField* pRspInfo)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnErrRtnOptionSelfCloseAction(gcnew OptionSelfCloseActionField(pOptionSelfCloseAction), gcnew RspInfoField(pRspInfo));
	}

	void CTraderSpi::OnRtnCombAction(CThostFtdcCombActionField* pCombAction)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRtnCombAction(gcnew CombActionField(pCombAction));
	}

	void CTraderSpi::OnErrRtnCombActionInsert(CThostFtdcInputCombActionField* pInputCombAction, CThostFtdcRspInfoField* pRspInfo)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnErrRtnCombActionInsert(gcnew InputCombActionField(pInputCombAction), gcnew RspInfoField(pRspInfo));
	}

	void CTraderSpi::OnRspQryContractBank(CThostFtdcContractBankField* pContractBank, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQryContractBank(gcnew ContractBankField(pContractBank), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQryParkedOrder(CThostFtdcParkedOrderField* pParkedOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQryParkedOrder(gcnew ParkedOrderField(pParkedOrder), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQryParkedOrderAction(CThostFtdcParkedOrderActionField* pParkedOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQryParkedOrderAction(gcnew ParkedOrderActionField(pParkedOrderAction), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQryTradingNotice(CThostFtdcTradingNoticeField* pTradingNotice, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQryTradingNotice(gcnew TradingNoticeField(pTradingNotice), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQryBrokerTradingParams(CThostFtdcBrokerTradingParamsField* pBrokerTradingParams, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQryBrokerTradingParams(gcnew BrokerTradingParamsField(pBrokerTradingParams), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQryBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosField* pBrokerTradingAlgos, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQryBrokerTradingAlgos(gcnew BrokerTradingAlgosField(pBrokerTradingAlgos), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenField* pQueryCFMMCTradingAccountToken, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQueryCFMMCTradingAccountToken(gcnew QueryCFMMCTradingAccountTokenField(pQueryCFMMCTradingAccountToken), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRtnFromBankToFutureByBank(CThostFtdcRspTransferField* pRspTransfer)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRtnFromBankToFutureByBank(gcnew RspTransferField(pRspTransfer));
	}

	void CTraderSpi::OnRtnFromFutureToBankByBank(CThostFtdcRspTransferField* pRspTransfer)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRtnFromFutureToBankByBank(gcnew RspTransferField(pRspTransfer));
	}

	void CTraderSpi::OnRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealField* pRspRepeal)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRtnRepealFromBankToFutureByBank(gcnew RspRepealField(pRspRepeal));
	}

	void CTraderSpi::OnRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealField* pRspRepeal)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRtnRepealFromFutureToBankByBank(gcnew RspRepealField(pRspRepeal));
	}

	void CTraderSpi::OnRtnFromBankToFutureByFuture(CThostFtdcRspTransferField* pRspTransfer)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRtnFromBankToFutureByFuture(gcnew RspTransferField(pRspTransfer));
	}

	void CTraderSpi::OnRtnFromFutureToBankByFuture(CThostFtdcRspTransferField* pRspTransfer)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRtnFromFutureToBankByFuture(gcnew RspTransferField(pRspTransfer));
	}

	void CTraderSpi::OnRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealField* pRspRepeal)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRtnRepealFromBankToFutureByFutureManual(gcnew RspRepealField(pRspRepeal));
	}

	void CTraderSpi::OnRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealField* pRspRepeal)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRtnRepealFromFutureToBankByFutureManual(gcnew RspRepealField(pRspRepeal));
	}

	void CTraderSpi::OnRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField* pNotifyQueryAccount)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRtnQueryBankBalanceByFuture(gcnew NotifyQueryAccountField(pNotifyQueryAccount));
	}

	void CTraderSpi::OnErrRtnBankToFutureByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnErrRtnBankToFutureByFuture(gcnew ReqTransferField(pReqTransfer), gcnew RspInfoField(pRspInfo));
	}

	void CTraderSpi::OnErrRtnFutureToBankByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnErrRtnFutureToBankByFuture(gcnew ReqTransferField(pReqTransfer), gcnew RspInfoField(pRspInfo));
	}

	void CTraderSpi::OnErrRtnRepealBankToFutureByFutureManual(CThostFtdcReqRepealField* pReqRepeal, CThostFtdcRspInfoField* pRspInfo)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnErrRtnRepealBankToFutureByFutureManual(gcnew ReqRepealField(pReqRepeal), gcnew RspInfoField(pRspInfo));
	}

	void CTraderSpi::OnErrRtnRepealFutureToBankByFutureManual(CThostFtdcReqRepealField* pReqRepeal, CThostFtdcRspInfoField* pRspInfo)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnErrRtnRepealFutureToBankByFutureManual(gcnew ReqRepealField(pReqRepeal), gcnew RspInfoField(pRspInfo));
	}

	void CTraderSpi::OnErrRtnQueryBankBalanceByFuture(CThostFtdcReqQueryAccountField* pReqQueryAccount, CThostFtdcRspInfoField* pRspInfo)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnErrRtnQueryBankBalanceByFuture(gcnew ReqQueryAccountField(pReqQueryAccount), gcnew RspInfoField(pRspInfo));
	}

	void CTraderSpi::OnRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealField* pRspRepeal)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRtnRepealFromBankToFutureByFuture(gcnew RspRepealField(pRspRepeal));
	}

	void CTraderSpi::OnRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealField* pRspRepeal)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRtnRepealFromFutureToBankByFuture(gcnew RspRepealField(pRspRepeal));
	}

	void CTraderSpi::OnRspFromBankToFutureByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspFromBankToFutureByFuture(gcnew ReqTransferField(pReqTransfer), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspFromFutureToBankByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspFromFutureToBankByFuture(gcnew ReqTransferField(pReqTransfer), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField* pReqQueryAccount, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQueryBankAccountMoneyByFuture(gcnew ReqQueryAccountField(pReqQueryAccount), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRtnOpenAccountByBank(CThostFtdcOpenAccountField* pOpenAccount)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRtnOpenAccountByBank(gcnew OpenAccountField(pOpenAccount));
	}

	void CTraderSpi::OnRtnCancelAccountByBank(CThostFtdcCancelAccountField* pCancelAccount)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRtnCancelAccountByBank(gcnew CancelAccountField(pCancelAccount));
	}

	void CTraderSpi::OnRtnChangeAccountByBank(CThostFtdcChangeAccountField* pChangeAccount)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRtnChangeAccountByBank(gcnew ChangeAccountField(pChangeAccount));
	}

	void CTraderSpi::OnRspQryClassifiedInstrument(CThostFtdcInstrumentField* pInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQryClassifiedInstrument(gcnew InstrumentField(pInstrument), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQryCombPromotionParam(CThostFtdcCombPromotionParamField* pCombPromotionParam, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQryCombPromotionParam(gcnew CombPromotionParamField(pCombPromotionParam), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQryRiskSettleInvstPosition(CThostFtdcRiskSettleInvstPositionField* pRiskSettleInvstPosition, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQryRiskSettleInvstPosition(gcnew RiskSettleInvstPositionField(pRiskSettleInvstPosition), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	void CTraderSpi::OnRspQryRiskSettleProductStatus(CThostFtdcRiskSettleProductStatusField* pRiskSettleProductStatus, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		safe_cast<TraderSpi^>(intPtr2ManagedClass(this->pTraderSpi))->OnRspQryRiskSettleProductStatus(gcnew RiskSettleProductStatusField(pRiskSettleProductStatus), gcnew RspInfoField(pRspInfo), nRequestID, bIsLast);
	}


}
