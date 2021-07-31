#include "pch.h"
#include "TraderSpi.h"

namespace PhoenixCTP
{
	class CTraderSpi;


	TraderSpi::TraderSpi()
	{
		System::IntPtr pTraderSpi = managedClass2IntPtr(this);
		CTraderSpi* pCTraderSpi = new CTraderSpi(pTraderSpi);
		pCSpi = pCTraderSpi;
	}

	TraderSpi::TraderSpi(TraderApi^ pTraderApi): TraderSpi()
	{
		this->SetApi(pTraderApi);
	}

	void TraderSpi::SetApi(TraderApi^ pTraderApi)
	{
		this->Api = pTraderApi;
	}

	void TraderSpi::OnFrontConnected()
	{
		this->FrontConnected(this, gcnew FrontConnectedArgs());
	}

	void TraderSpi::OnFrontConnected(TraderSpi^ sender, FrontConnectedArgs^ e)
	{
		this->FrontConnected(sender, e);
	}

	void TraderSpi::OnFrontDisconnected(int nReason)
	{
		this->FrontDisconnected(this, gcnew FrontDisconnectedArgs(nReason));
	}

	void TraderSpi::OnFrontDisconnected(TraderSpi^ sender, FrontDisconnectedArgs^ e)
	{
		this->FrontDisconnected(sender, e);
	}

	void TraderSpi::OnHeartBeatWarning(int nTimeLapse)
	{
		this->HeartBeatWarning(this, gcnew HeartBeatWarningArgs(nTimeLapse));
	}

	void TraderSpi::OnHeartBeatWarning(TraderSpi^ sender, HeartBeatWarningArgs^ e)
	{
		this->HeartBeatWarning(sender, e);
	}

	void TraderSpi::OnRspAuthenticate(RspAuthenticateField^ pRspAuthenticateField, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspAuthenticate(this, gcnew RspAuthenticateArgs(pRspAuthenticateField, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspAuthenticate(TraderSpi^ sender, RspAuthenticateArgs^ e)
	{
		this->RspAuthenticate(sender, e);
	}

	void TraderSpi::OnRspUserLogin(RspUserLoginField^ pRspUserLogin, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspUserLogin(this, gcnew RspUserLoginArgs(pRspUserLogin, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspUserLogin(TraderSpi^ sender, RspUserLoginArgs^ e)
	{
		this->RspUserLogin(sender, e);
	}

	void TraderSpi::OnRspUserLogout(UserLogoutField^ pUserLogout, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspUserLogout(this, gcnew RspUserLogoutArgs(pUserLogout, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspUserLogout(TraderSpi^ sender, RspUserLogoutArgs^ e)
	{
		this->RspUserLogout(sender, e);
	}

	void TraderSpi::OnRspUserPasswordUpdate(UserPasswordUpdateField^ pUserPasswordUpdate, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspUserPasswordUpdate(this, gcnew RspUserPasswordUpdateArgs(pUserPasswordUpdate, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspUserPasswordUpdate(TraderSpi^ sender, RspUserPasswordUpdateArgs^ e)
	{
		this->RspUserPasswordUpdate(sender, e);
	}

	void TraderSpi::OnRspTradingAccountPasswordUpdate(TradingAccountPasswordUpdateField^ pTradingAccountPasswordUpdate, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspTradingAccountPasswordUpdate(this, gcnew RspTradingAccountPasswordUpdateArgs(pTradingAccountPasswordUpdate, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspTradingAccountPasswordUpdate(TraderSpi^ sender, RspTradingAccountPasswordUpdateArgs^ e)
	{
		this->RspTradingAccountPasswordUpdate(sender, e);
	}

	void TraderSpi::OnRspUserAuthMethod(RspUserAuthMethodField^ pRspUserAuthMethod, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspUserAuthMethod(this, gcnew RspUserAuthMethodArgs(pRspUserAuthMethod, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspUserAuthMethod(TraderSpi^ sender, RspUserAuthMethodArgs^ e)
	{
		this->RspUserAuthMethod(sender, e);
	}

	void TraderSpi::OnRspGenUserCaptcha(RspGenUserCaptchaField^ pRspGenUserCaptcha, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspGenUserCaptcha(this, gcnew RspGenUserCaptchaArgs(pRspGenUserCaptcha, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspGenUserCaptcha(TraderSpi^ sender, RspGenUserCaptchaArgs^ e)
	{
		this->RspGenUserCaptcha(sender, e);
	}

	void TraderSpi::OnRspGenUserText(RspGenUserTextField^ pRspGenUserText, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspGenUserText(this, gcnew RspGenUserTextArgs(pRspGenUserText, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspGenUserText(TraderSpi^ sender, RspGenUserTextArgs^ e)
	{
		this->RspGenUserText(sender, e);
	}

	void TraderSpi::OnRspOrderInsert(InputOrderField^ pInputOrder, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspOrderInsert(this, gcnew RspOrderInsertArgs(pInputOrder, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspOrderInsert(TraderSpi^ sender, RspOrderInsertArgs^ e)
	{
		this->RspOrderInsert(sender, e);
	}

	void TraderSpi::OnRspParkedOrderInsert(ParkedOrderField^ pParkedOrder, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspParkedOrderInsert(this, gcnew RspParkedOrderInsertArgs(pParkedOrder, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspParkedOrderInsert(TraderSpi^ sender, RspParkedOrderInsertArgs^ e)
	{
		this->RspParkedOrderInsert(sender, e);
	}

	void TraderSpi::OnRspParkedOrderAction(ParkedOrderActionField^ pParkedOrderAction, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspParkedOrderAction(this, gcnew RspParkedOrderActionArgs(pParkedOrderAction, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspParkedOrderAction(TraderSpi^ sender, RspParkedOrderActionArgs^ e)
	{
		this->RspParkedOrderAction(sender, e);
	}

	void TraderSpi::OnRspOrderAction(InputOrderActionField^ pInputOrderAction, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspOrderAction(this, gcnew RspOrderActionArgs(pInputOrderAction, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspOrderAction(TraderSpi^ sender, RspOrderActionArgs^ e)
	{
		this->RspOrderAction(sender, e);
	}

	void TraderSpi::OnRspQryMaxOrderVolume(QryMaxOrderVolumeField^ pQryMaxOrderVolume, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryMaxOrderVolume(this, gcnew RspQryMaxOrderVolumeArgs(pQryMaxOrderVolume, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQryMaxOrderVolume(TraderSpi^ sender, RspQryMaxOrderVolumeArgs^ e)
	{
		this->RspQryMaxOrderVolume(sender, e);
	}

	void TraderSpi::OnRspSettlementInfoConfirm(SettlementInfoConfirmField^ pSettlementInfoConfirm, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspSettlementInfoConfirm(this, gcnew RspSettlementInfoConfirmArgs(pSettlementInfoConfirm, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspSettlementInfoConfirm(TraderSpi^ sender, RspSettlementInfoConfirmArgs^ e)
	{
		this->RspSettlementInfoConfirm(sender, e);
	}

	void TraderSpi::OnRspRemoveParkedOrder(RemoveParkedOrderField^ pRemoveParkedOrder, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspRemoveParkedOrder(this, gcnew RspRemoveParkedOrderArgs(pRemoveParkedOrder, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspRemoveParkedOrder(TraderSpi^ sender, RspRemoveParkedOrderArgs^ e)
	{
		this->RspRemoveParkedOrder(sender, e);
	}

	void TraderSpi::OnRspRemoveParkedOrderAction(RemoveParkedOrderActionField^ pRemoveParkedOrderAction, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspRemoveParkedOrderAction(this, gcnew RspRemoveParkedOrderActionArgs(pRemoveParkedOrderAction, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspRemoveParkedOrderAction(TraderSpi^ sender, RspRemoveParkedOrderActionArgs^ e)
	{
		this->RspRemoveParkedOrderAction(sender, e);
	}

	void TraderSpi::OnRspExecOrderInsert(InputExecOrderField^ pInputExecOrder, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspExecOrderInsert(this, gcnew RspExecOrderInsertArgs(pInputExecOrder, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspExecOrderInsert(TraderSpi^ sender, RspExecOrderInsertArgs^ e)
	{
		this->RspExecOrderInsert(sender, e);
	}

	void TraderSpi::OnRspExecOrderAction(InputExecOrderActionField^ pInputExecOrderAction, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspExecOrderAction(this, gcnew RspExecOrderActionArgs(pInputExecOrderAction, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspExecOrderAction(TraderSpi^ sender, RspExecOrderActionArgs^ e)
	{
		this->RspExecOrderAction(sender, e);
	}

	void TraderSpi::OnRspForQuoteInsert(InputForQuoteField^ pInputForQuote, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspForQuoteInsert(this, gcnew RspForQuoteInsertArgs(pInputForQuote, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspForQuoteInsert(TraderSpi^ sender, RspForQuoteInsertArgs^ e)
	{
		this->RspForQuoteInsert(sender, e);
	}

	void TraderSpi::OnRspQuoteInsert(InputQuoteField^ pInputQuote, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQuoteInsert(this, gcnew RspQuoteInsertArgs(pInputQuote, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQuoteInsert(TraderSpi^ sender, RspQuoteInsertArgs^ e)
	{
		this->RspQuoteInsert(sender, e);
	}

	void TraderSpi::OnRspQuoteAction(InputQuoteActionField^ pInputQuoteAction, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQuoteAction(this, gcnew RspQuoteActionArgs(pInputQuoteAction, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQuoteAction(TraderSpi^ sender, RspQuoteActionArgs^ e)
	{
		this->RspQuoteAction(sender, e);
	}

	void TraderSpi::OnRspBatchOrderAction(InputBatchOrderActionField^ pInputBatchOrderAction, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspBatchOrderAction(this, gcnew RspBatchOrderActionArgs(pInputBatchOrderAction, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspBatchOrderAction(TraderSpi^ sender, RspBatchOrderActionArgs^ e)
	{
		this->RspBatchOrderAction(sender, e);
	}

	void TraderSpi::OnRspOptionSelfCloseInsert(InputOptionSelfCloseField^ pInputOptionSelfClose, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspOptionSelfCloseInsert(this, gcnew RspOptionSelfCloseInsertArgs(pInputOptionSelfClose, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspOptionSelfCloseInsert(TraderSpi^ sender, RspOptionSelfCloseInsertArgs^ e)
	{
		this->RspOptionSelfCloseInsert(sender, e);
	}

	void TraderSpi::OnRspOptionSelfCloseAction(InputOptionSelfCloseActionField^ pInputOptionSelfCloseAction, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspOptionSelfCloseAction(this, gcnew RspOptionSelfCloseActionArgs(pInputOptionSelfCloseAction, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspOptionSelfCloseAction(TraderSpi^ sender, RspOptionSelfCloseActionArgs^ e)
	{
		this->RspOptionSelfCloseAction(sender, e);
	}

	void TraderSpi::OnRspCombActionInsert(InputCombActionField^ pInputCombAction, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspCombActionInsert(this, gcnew RspCombActionInsertArgs(pInputCombAction, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspCombActionInsert(TraderSpi^ sender, RspCombActionInsertArgs^ e)
	{
		this->RspCombActionInsert(sender, e);
	}

	void TraderSpi::OnRspQryOrder(OrderField^ pOrder, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryOrder(this, gcnew RspQryOrderArgs(pOrder, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQryOrder(TraderSpi^ sender, RspQryOrderArgs^ e)
	{
		this->RspQryOrder(sender, e);
	}

	void TraderSpi::OnRspQryTrade(TradeField^ pTrade, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryTrade(this, gcnew RspQryTradeArgs(pTrade, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQryTrade(TraderSpi^ sender, RspQryTradeArgs^ e)
	{
		this->RspQryTrade(sender, e);
	}

	void TraderSpi::OnRspQryInvestorPosition(InvestorPositionField^ pInvestorPosition, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryInvestorPosition(this, gcnew RspQryInvestorPositionArgs(pInvestorPosition, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQryInvestorPosition(TraderSpi^ sender, RspQryInvestorPositionArgs^ e)
	{
		this->RspQryInvestorPosition(sender, e);
	}

	void TraderSpi::OnRspQryTradingAccount(TradingAccountField^ pTradingAccount, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryTradingAccount(this, gcnew RspQryTradingAccountArgs(pTradingAccount, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQryTradingAccount(TraderSpi^ sender, RspQryTradingAccountArgs^ e)
	{
		this->RspQryTradingAccount(sender, e);
	}

	void TraderSpi::OnRspQryInvestor(InvestorField^ pInvestor, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryInvestor(this, gcnew RspQryInvestorArgs(pInvestor, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQryInvestor(TraderSpi^ sender, RspQryInvestorArgs^ e)
	{
		this->RspQryInvestor(sender, e);
	}

	void TraderSpi::OnRspQryTradingCode(TradingCodeField^ pTradingCode, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryTradingCode(this, gcnew RspQryTradingCodeArgs(pTradingCode, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQryTradingCode(TraderSpi^ sender, RspQryTradingCodeArgs^ e)
	{
		this->RspQryTradingCode(sender, e);
	}

	void TraderSpi::OnRspQryInstrumentMarginRate(InstrumentMarginRateField^ pInstrumentMarginRate, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryInstrumentMarginRate(this, gcnew RspQryInstrumentMarginRateArgs(pInstrumentMarginRate, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQryInstrumentMarginRate(TraderSpi^ sender, RspQryInstrumentMarginRateArgs^ e)
	{
		this->RspQryInstrumentMarginRate(sender, e);
	}

	void TraderSpi::OnRspQryInstrumentCommissionRate(InstrumentCommissionRateField^ pInstrumentCommissionRate, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryInstrumentCommissionRate(this, gcnew RspQryInstrumentCommissionRateArgs(pInstrumentCommissionRate, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQryInstrumentCommissionRate(TraderSpi^ sender, RspQryInstrumentCommissionRateArgs^ e)
	{
		this->RspQryInstrumentCommissionRate(sender, e);
	}

	void TraderSpi::OnRspQryExchange(ExchangeField^ pExchange, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryExchange(this, gcnew RspQryExchangeArgs(pExchange, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQryExchange(TraderSpi^ sender, RspQryExchangeArgs^ e)
	{
		this->RspQryExchange(sender, e);
	}

	void TraderSpi::OnRspQryProduct(ProductField^ pProduct, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryProduct(this, gcnew RspQryProductArgs(pProduct, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQryProduct(TraderSpi^ sender, RspQryProductArgs^ e)
	{
		this->RspQryProduct(sender, e);
	}

	void TraderSpi::OnRspQryInstrument(InstrumentField^ pInstrument, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryInstrument(this, gcnew RspQryInstrumentArgs(pInstrument, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQryInstrument(TraderSpi^ sender, RspQryInstrumentArgs^ e)
	{
		this->RspQryInstrument(sender, e);
	}

	void TraderSpi::OnRspQryDepthMarketData(DepthMarketDataField^ pDepthMarketData, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryDepthMarketData(this, gcnew RspQryDepthMarketDataArgs(pDepthMarketData, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQryDepthMarketData(TraderSpi^ sender, RspQryDepthMarketDataArgs^ e)
	{
		this->RspQryDepthMarketData(sender, e);
	}

	void TraderSpi::OnRspQrySettlementInfo(SettlementInfoField^ pSettlementInfo, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQrySettlementInfo(this, gcnew RspQrySettlementInfoArgs(pSettlementInfo, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQrySettlementInfo(TraderSpi^ sender, RspQrySettlementInfoArgs^ e)
	{
		this->RspQrySettlementInfo(sender, e);
	}

	void TraderSpi::OnRspQryTransferBank(TransferBankField^ pTransferBank, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryTransferBank(this, gcnew RspQryTransferBankArgs(pTransferBank, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQryTransferBank(TraderSpi^ sender, RspQryTransferBankArgs^ e)
	{
		this->RspQryTransferBank(sender, e);
	}

	void TraderSpi::OnRspQryInvestorPositionDetail(InvestorPositionDetailField^ pInvestorPositionDetail, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryInvestorPositionDetail(this, gcnew RspQryInvestorPositionDetailArgs(pInvestorPositionDetail, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQryInvestorPositionDetail(TraderSpi^ sender, RspQryInvestorPositionDetailArgs^ e)
	{
		this->RspQryInvestorPositionDetail(sender, e);
	}

	void TraderSpi::OnRspQryNotice(NoticeField^ pNotice, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryNotice(this, gcnew RspQryNoticeArgs(pNotice, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQryNotice(TraderSpi^ sender, RspQryNoticeArgs^ e)
	{
		this->RspQryNotice(sender, e);
	}

	void TraderSpi::OnRspQrySettlementInfoConfirm(SettlementInfoConfirmField^ pSettlementInfoConfirm, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQrySettlementInfoConfirm(this, gcnew RspQrySettlementInfoConfirmArgs(pSettlementInfoConfirm, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQrySettlementInfoConfirm(TraderSpi^ sender, RspQrySettlementInfoConfirmArgs^ e)
	{
		this->RspQrySettlementInfoConfirm(sender, e);
	}

	void TraderSpi::OnRspQryInvestorPositionCombineDetail(InvestorPositionCombineDetailField^ pInvestorPositionCombineDetail, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryInvestorPositionCombineDetail(this, gcnew RspQryInvestorPositionCombineDetailArgs(pInvestorPositionCombineDetail, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQryInvestorPositionCombineDetail(TraderSpi^ sender, RspQryInvestorPositionCombineDetailArgs^ e)
	{
		this->RspQryInvestorPositionCombineDetail(sender, e);
	}

	void TraderSpi::OnRspQryCFMMCTradingAccountKey(CFMMCTradingAccountKeyField^ pCFMMCTradingAccountKey, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryCFMMCTradingAccountKey(this, gcnew RspQryCFMMCTradingAccountKeyArgs(pCFMMCTradingAccountKey, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQryCFMMCTradingAccountKey(TraderSpi^ sender, RspQryCFMMCTradingAccountKeyArgs^ e)
	{
		this->RspQryCFMMCTradingAccountKey(sender, e);
	}

	void TraderSpi::OnRspQryEWarrantOffset(EWarrantOffsetField^ pEWarrantOffset, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryEWarrantOffset(this, gcnew RspQryEWarrantOffsetArgs(pEWarrantOffset, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQryEWarrantOffset(TraderSpi^ sender, RspQryEWarrantOffsetArgs^ e)
	{
		this->RspQryEWarrantOffset(sender, e);
	}

	void TraderSpi::OnRspQryInvestorProductGroupMargin(InvestorProductGroupMarginField^ pInvestorProductGroupMargin, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryInvestorProductGroupMargin(this, gcnew RspQryInvestorProductGroupMarginArgs(pInvestorProductGroupMargin, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQryInvestorProductGroupMargin(TraderSpi^ sender, RspQryInvestorProductGroupMarginArgs^ e)
	{
		this->RspQryInvestorProductGroupMargin(sender, e);
	}

	void TraderSpi::OnRspQryExchangeMarginRate(ExchangeMarginRateField^ pExchangeMarginRate, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryExchangeMarginRate(this, gcnew RspQryExchangeMarginRateArgs(pExchangeMarginRate, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQryExchangeMarginRate(TraderSpi^ sender, RspQryExchangeMarginRateArgs^ e)
	{
		this->RspQryExchangeMarginRate(sender, e);
	}

	void TraderSpi::OnRspQryExchangeMarginRateAdjust(ExchangeMarginRateAdjustField^ pExchangeMarginRateAdjust, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryExchangeMarginRateAdjust(this, gcnew RspQryExchangeMarginRateAdjustArgs(pExchangeMarginRateAdjust, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQryExchangeMarginRateAdjust(TraderSpi^ sender, RspQryExchangeMarginRateAdjustArgs^ e)
	{
		this->RspQryExchangeMarginRateAdjust(sender, e);
	}

	void TraderSpi::OnRspQryExchangeRate(ExchangeRateField^ pExchangeRate, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryExchangeRate(this, gcnew RspQryExchangeRateArgs(pExchangeRate, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQryExchangeRate(TraderSpi^ sender, RspQryExchangeRateArgs^ e)
	{
		this->RspQryExchangeRate(sender, e);
	}

	void TraderSpi::OnRspQrySecAgentACIDMap(SecAgentACIDMapField^ pSecAgentACIDMap, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQrySecAgentACIDMap(this, gcnew RspQrySecAgentACIDMapArgs(pSecAgentACIDMap, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQrySecAgentACIDMap(TraderSpi^ sender, RspQrySecAgentACIDMapArgs^ e)
	{
		this->RspQrySecAgentACIDMap(sender, e);
	}

	void TraderSpi::OnRspQryProductExchRate(ProductExchRateField^ pProductExchRate, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryProductExchRate(this, gcnew RspQryProductExchRateArgs(pProductExchRate, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQryProductExchRate(TraderSpi^ sender, RspQryProductExchRateArgs^ e)
	{
		this->RspQryProductExchRate(sender, e);
	}

	void TraderSpi::OnRspQryProductGroup(ProductGroupField^ pProductGroup, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryProductGroup(this, gcnew RspQryProductGroupArgs(pProductGroup, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQryProductGroup(TraderSpi^ sender, RspQryProductGroupArgs^ e)
	{
		this->RspQryProductGroup(sender, e);
	}

	void TraderSpi::OnRspQryMMInstrumentCommissionRate(MMInstrumentCommissionRateField^ pMMInstrumentCommissionRate, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryMMInstrumentCommissionRate(this, gcnew RspQryMMInstrumentCommissionRateArgs(pMMInstrumentCommissionRate, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQryMMInstrumentCommissionRate(TraderSpi^ sender, RspQryMMInstrumentCommissionRateArgs^ e)
	{
		this->RspQryMMInstrumentCommissionRate(sender, e);
	}

	void TraderSpi::OnRspQryMMOptionInstrCommRate(MMOptionInstrCommRateField^ pMMOptionInstrCommRate, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryMMOptionInstrCommRate(this, gcnew RspQryMMOptionInstrCommRateArgs(pMMOptionInstrCommRate, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQryMMOptionInstrCommRate(TraderSpi^ sender, RspQryMMOptionInstrCommRateArgs^ e)
	{
		this->RspQryMMOptionInstrCommRate(sender, e);
	}

	void TraderSpi::OnRspQryInstrumentOrderCommRate(InstrumentOrderCommRateField^ pInstrumentOrderCommRate, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryInstrumentOrderCommRate(this, gcnew RspQryInstrumentOrderCommRateArgs(pInstrumentOrderCommRate, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQryInstrumentOrderCommRate(TraderSpi^ sender, RspQryInstrumentOrderCommRateArgs^ e)
	{
		this->RspQryInstrumentOrderCommRate(sender, e);
	}

	void TraderSpi::OnRspQrySecAgentTradingAccount(TradingAccountField^ pTradingAccount, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQrySecAgentTradingAccount(this, gcnew RspQrySecAgentTradingAccountArgs(pTradingAccount, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQrySecAgentTradingAccount(TraderSpi^ sender, RspQrySecAgentTradingAccountArgs^ e)
	{
		this->RspQrySecAgentTradingAccount(sender, e);
	}

	void TraderSpi::OnRspQrySecAgentCheckMode(SecAgentCheckModeField^ pSecAgentCheckMode, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQrySecAgentCheckMode(this, gcnew RspQrySecAgentCheckModeArgs(pSecAgentCheckMode, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQrySecAgentCheckMode(TraderSpi^ sender, RspQrySecAgentCheckModeArgs^ e)
	{
		this->RspQrySecAgentCheckMode(sender, e);
	}

	void TraderSpi::OnRspQrySecAgentTradeInfo(SecAgentTradeInfoField^ pSecAgentTradeInfo, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQrySecAgentTradeInfo(this, gcnew RspQrySecAgentTradeInfoArgs(pSecAgentTradeInfo, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQrySecAgentTradeInfo(TraderSpi^ sender, RspQrySecAgentTradeInfoArgs^ e)
	{
		this->RspQrySecAgentTradeInfo(sender, e);
	}

	void TraderSpi::OnRspQryOptionInstrTradeCost(OptionInstrTradeCostField^ pOptionInstrTradeCost, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryOptionInstrTradeCost(this, gcnew RspQryOptionInstrTradeCostArgs(pOptionInstrTradeCost, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQryOptionInstrTradeCost(TraderSpi^ sender, RspQryOptionInstrTradeCostArgs^ e)
	{
		this->RspQryOptionInstrTradeCost(sender, e);
	}

	void TraderSpi::OnRspQryOptionInstrCommRate(OptionInstrCommRateField^ pOptionInstrCommRate, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryOptionInstrCommRate(this, gcnew RspQryOptionInstrCommRateArgs(pOptionInstrCommRate, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQryOptionInstrCommRate(TraderSpi^ sender, RspQryOptionInstrCommRateArgs^ e)
	{
		this->RspQryOptionInstrCommRate(sender, e);
	}

	void TraderSpi::OnRspQryExecOrder(ExecOrderField^ pExecOrder, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryExecOrder(this, gcnew RspQryExecOrderArgs(pExecOrder, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQryExecOrder(TraderSpi^ sender, RspQryExecOrderArgs^ e)
	{
		this->RspQryExecOrder(sender, e);
	}

	void TraderSpi::OnRspQryForQuote(ForQuoteField^ pForQuote, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryForQuote(this, gcnew RspQryForQuoteArgs(pForQuote, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQryForQuote(TraderSpi^ sender, RspQryForQuoteArgs^ e)
	{
		this->RspQryForQuote(sender, e);
	}

	void TraderSpi::OnRspQryQuote(QuoteField^ pQuote, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryQuote(this, gcnew RspQryQuoteArgs(pQuote, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQryQuote(TraderSpi^ sender, RspQryQuoteArgs^ e)
	{
		this->RspQryQuote(sender, e);
	}

	void TraderSpi::OnRspQryOptionSelfClose(OptionSelfCloseField^ pOptionSelfClose, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryOptionSelfClose(this, gcnew RspQryOptionSelfCloseArgs(pOptionSelfClose, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQryOptionSelfClose(TraderSpi^ sender, RspQryOptionSelfCloseArgs^ e)
	{
		this->RspQryOptionSelfClose(sender, e);
	}

	void TraderSpi::OnRspQryInvestUnit(InvestUnitField^ pInvestUnit, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryInvestUnit(this, gcnew RspQryInvestUnitArgs(pInvestUnit, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQryInvestUnit(TraderSpi^ sender, RspQryInvestUnitArgs^ e)
	{
		this->RspQryInvestUnit(sender, e);
	}

	void TraderSpi::OnRspQryCombInstrumentGuard(CombInstrumentGuardField^ pCombInstrumentGuard, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryCombInstrumentGuard(this, gcnew RspQryCombInstrumentGuardArgs(pCombInstrumentGuard, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQryCombInstrumentGuard(TraderSpi^ sender, RspQryCombInstrumentGuardArgs^ e)
	{
		this->RspQryCombInstrumentGuard(sender, e);
	}

	void TraderSpi::OnRspQryCombAction(CombActionField^ pCombAction, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryCombAction(this, gcnew RspQryCombActionArgs(pCombAction, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQryCombAction(TraderSpi^ sender, RspQryCombActionArgs^ e)
	{
		this->RspQryCombAction(sender, e);
	}

	void TraderSpi::OnRspQryTransferSerial(TransferSerialField^ pTransferSerial, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryTransferSerial(this, gcnew RspQryTransferSerialArgs(pTransferSerial, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQryTransferSerial(TraderSpi^ sender, RspQryTransferSerialArgs^ e)
	{
		this->RspQryTransferSerial(sender, e);
	}

	void TraderSpi::OnRspQryAccountregister(AccountregisterField^ pAccountregister, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryAccountregister(this, gcnew RspQryAccountregisterArgs(pAccountregister, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQryAccountregister(TraderSpi^ sender, RspQryAccountregisterArgs^ e)
	{
		this->RspQryAccountregister(sender, e);
	}

	void TraderSpi::OnRspError(RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspError(this, gcnew RspErrorArgs(pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspError(TraderSpi^ sender, RspErrorArgs^ e)
	{
		this->RspError(sender, e);
	}

	void TraderSpi::OnRtnOrder(OrderField^ pOrder)
	{
		this->RtnOrder(this, gcnew RtnOrderArgs(pOrder));
	}

	void TraderSpi::OnRtnOrder(TraderSpi^ sender, RtnOrderArgs^ e)
	{
		this->RtnOrder(sender, e);
	}

	void TraderSpi::OnRtnTrade(TradeField^ pTrade)
	{
		this->RtnTrade(this, gcnew RtnTradeArgs(pTrade));
	}

	void TraderSpi::OnRtnTrade(TraderSpi^ sender, RtnTradeArgs^ e)
	{
		this->RtnTrade(sender, e);
	}

	void TraderSpi::OnErrRtnOrderInsert(InputOrderField^ pInputOrder, RspInfoField^ pRspInfo)
	{
		this->ErrRtnOrderInsert(this, gcnew ErrRtnOrderInsertArgs(pInputOrder, pRspInfo));
	}

	void TraderSpi::OnErrRtnOrderInsert(TraderSpi^ sender, ErrRtnOrderInsertArgs^ e)
	{
		this->ErrRtnOrderInsert(sender, e);
	}

	void TraderSpi::OnErrRtnOrderAction(OrderActionField^ pOrderAction, RspInfoField^ pRspInfo)
	{
		this->ErrRtnOrderAction(this, gcnew ErrRtnOrderActionArgs(pOrderAction, pRspInfo));
	}

	void TraderSpi::OnErrRtnOrderAction(TraderSpi^ sender, ErrRtnOrderActionArgs^ e)
	{
		this->ErrRtnOrderAction(sender, e);
	}

	void TraderSpi::OnRtnInstrumentStatus(InstrumentStatusField^ pInstrumentStatus)
	{
		this->RtnInstrumentStatus(this, gcnew RtnInstrumentStatusArgs(pInstrumentStatus));
	}

	void TraderSpi::OnRtnInstrumentStatus(TraderSpi^ sender, RtnInstrumentStatusArgs^ e)
	{
		this->RtnInstrumentStatus(sender, e);
	}

	void TraderSpi::OnRtnBulletin(BulletinField^ pBulletin)
	{
		this->RtnBulletin(this, gcnew RtnBulletinArgs(pBulletin));
	}

	void TraderSpi::OnRtnBulletin(TraderSpi^ sender, RtnBulletinArgs^ e)
	{
		this->RtnBulletin(sender, e);
	}

	void TraderSpi::OnRtnTradingNotice(TradingNoticeInfoField^ pTradingNoticeInfo)
	{
		this->RtnTradingNotice(this, gcnew RtnTradingNoticeArgs(pTradingNoticeInfo));
	}

	void TraderSpi::OnRtnTradingNotice(TraderSpi^ sender, RtnTradingNoticeArgs^ e)
	{
		this->RtnTradingNotice(sender, e);
	}

	void TraderSpi::OnRtnErrorConditionalOrder(ErrorConditionalOrderField^ pErrorConditionalOrder)
	{
		this->RtnErrorConditionalOrder(this, gcnew RtnErrorConditionalOrderArgs(pErrorConditionalOrder));
	}

	void TraderSpi::OnRtnErrorConditionalOrder(TraderSpi^ sender, RtnErrorConditionalOrderArgs^ e)
	{
		this->RtnErrorConditionalOrder(sender, e);
	}

	void TraderSpi::OnRtnExecOrder(ExecOrderField^ pExecOrder)
	{
		this->RtnExecOrder(this, gcnew RtnExecOrderArgs(pExecOrder));
	}

	void TraderSpi::OnRtnExecOrder(TraderSpi^ sender, RtnExecOrderArgs^ e)
	{
		this->RtnExecOrder(sender, e);
	}

	void TraderSpi::OnErrRtnExecOrderInsert(InputExecOrderField^ pInputExecOrder, RspInfoField^ pRspInfo)
	{
		this->ErrRtnExecOrderInsert(this, gcnew ErrRtnExecOrderInsertArgs(pInputExecOrder, pRspInfo));
	}

	void TraderSpi::OnErrRtnExecOrderInsert(TraderSpi^ sender, ErrRtnExecOrderInsertArgs^ e)
	{
		this->ErrRtnExecOrderInsert(sender, e);
	}

	void TraderSpi::OnErrRtnExecOrderAction(ExecOrderActionField^ pExecOrderAction, RspInfoField^ pRspInfo)
	{
		this->ErrRtnExecOrderAction(this, gcnew ErrRtnExecOrderActionArgs(pExecOrderAction, pRspInfo));
	}

	void TraderSpi::OnErrRtnExecOrderAction(TraderSpi^ sender, ErrRtnExecOrderActionArgs^ e)
	{
		this->ErrRtnExecOrderAction(sender, e);
	}

	void TraderSpi::OnErrRtnForQuoteInsert(InputForQuoteField^ pInputForQuote, RspInfoField^ pRspInfo)
	{
		this->ErrRtnForQuoteInsert(this, gcnew ErrRtnForQuoteInsertArgs(pInputForQuote, pRspInfo));
	}

	void TraderSpi::OnErrRtnForQuoteInsert(TraderSpi^ sender, ErrRtnForQuoteInsertArgs^ e)
	{
		this->ErrRtnForQuoteInsert(sender, e);
	}

	void TraderSpi::OnRtnQuote(QuoteField^ pQuote)
	{
		this->RtnQuote(this, gcnew RtnQuoteArgs(pQuote));
	}

	void TraderSpi::OnRtnQuote(TraderSpi^ sender, RtnQuoteArgs^ e)
	{
		this->RtnQuote(sender, e);
	}

	void TraderSpi::OnErrRtnQuoteInsert(InputQuoteField^ pInputQuote, RspInfoField^ pRspInfo)
	{
		this->ErrRtnQuoteInsert(this, gcnew ErrRtnQuoteInsertArgs(pInputQuote, pRspInfo));
	}

	void TraderSpi::OnErrRtnQuoteInsert(TraderSpi^ sender, ErrRtnQuoteInsertArgs^ e)
	{
		this->ErrRtnQuoteInsert(sender, e);
	}

	void TraderSpi::OnErrRtnQuoteAction(QuoteActionField^ pQuoteAction, RspInfoField^ pRspInfo)
	{
		this->ErrRtnQuoteAction(this, gcnew ErrRtnQuoteActionArgs(pQuoteAction, pRspInfo));
	}

	void TraderSpi::OnErrRtnQuoteAction(TraderSpi^ sender, ErrRtnQuoteActionArgs^ e)
	{
		this->ErrRtnQuoteAction(sender, e);
	}

	void TraderSpi::OnRtnForQuoteRsp(ForQuoteRspField^ pForQuoteRsp)
	{
		this->RtnForQuoteRsp(this, gcnew RtnForQuoteRspArgs(pForQuoteRsp));
	}

	void TraderSpi::OnRtnForQuoteRsp(TraderSpi^ sender, RtnForQuoteRspArgs^ e)
	{
		this->RtnForQuoteRsp(sender, e);
	}

	void TraderSpi::OnRtnCFMMCTradingAccountToken(CFMMCTradingAccountTokenField^ pCFMMCTradingAccountToken)
	{
		this->RtnCFMMCTradingAccountToken(this, gcnew RtnCFMMCTradingAccountTokenArgs(pCFMMCTradingAccountToken));
	}

	void TraderSpi::OnRtnCFMMCTradingAccountToken(TraderSpi^ sender, RtnCFMMCTradingAccountTokenArgs^ e)
	{
		this->RtnCFMMCTradingAccountToken(sender, e);
	}

	void TraderSpi::OnErrRtnBatchOrderAction(BatchOrderActionField^ pBatchOrderAction, RspInfoField^ pRspInfo)
	{
		this->ErrRtnBatchOrderAction(this, gcnew ErrRtnBatchOrderActionArgs(pBatchOrderAction, pRspInfo));
	}

	void TraderSpi::OnErrRtnBatchOrderAction(TraderSpi^ sender, ErrRtnBatchOrderActionArgs^ e)
	{
		this->ErrRtnBatchOrderAction(sender, e);
	}

	void TraderSpi::OnRtnOptionSelfClose(OptionSelfCloseField^ pOptionSelfClose)
	{
		this->RtnOptionSelfClose(this, gcnew RtnOptionSelfCloseArgs(pOptionSelfClose));
	}

	void TraderSpi::OnRtnOptionSelfClose(TraderSpi^ sender, RtnOptionSelfCloseArgs^ e)
	{
		this->RtnOptionSelfClose(sender, e);
	}

	void TraderSpi::OnErrRtnOptionSelfCloseInsert(InputOptionSelfCloseField^ pInputOptionSelfClose, RspInfoField^ pRspInfo)
	{
		this->ErrRtnOptionSelfCloseInsert(this, gcnew ErrRtnOptionSelfCloseInsertArgs(pInputOptionSelfClose, pRspInfo));
	}

	void TraderSpi::OnErrRtnOptionSelfCloseInsert(TraderSpi^ sender, ErrRtnOptionSelfCloseInsertArgs^ e)
	{
		this->ErrRtnOptionSelfCloseInsert(sender, e);
	}

	void TraderSpi::OnErrRtnOptionSelfCloseAction(OptionSelfCloseActionField^ pOptionSelfCloseAction, RspInfoField^ pRspInfo)
	{
		this->ErrRtnOptionSelfCloseAction(this, gcnew ErrRtnOptionSelfCloseActionArgs(pOptionSelfCloseAction, pRspInfo));
	}

	void TraderSpi::OnErrRtnOptionSelfCloseAction(TraderSpi^ sender, ErrRtnOptionSelfCloseActionArgs^ e)
	{
		this->ErrRtnOptionSelfCloseAction(sender, e);
	}

	void TraderSpi::OnRtnCombAction(CombActionField^ pCombAction)
	{
		this->RtnCombAction(this, gcnew RtnCombActionArgs(pCombAction));
	}

	void TraderSpi::OnRtnCombAction(TraderSpi^ sender, RtnCombActionArgs^ e)
	{
		this->RtnCombAction(sender, e);
	}

	void TraderSpi::OnErrRtnCombActionInsert(InputCombActionField^ pInputCombAction, RspInfoField^ pRspInfo)
	{
		this->ErrRtnCombActionInsert(this, gcnew ErrRtnCombActionInsertArgs(pInputCombAction, pRspInfo));
	}

	void TraderSpi::OnErrRtnCombActionInsert(TraderSpi^ sender, ErrRtnCombActionInsertArgs^ e)
	{
		this->ErrRtnCombActionInsert(sender, e);
	}

	void TraderSpi::OnRspQryContractBank(ContractBankField^ pContractBank, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryContractBank(this, gcnew RspQryContractBankArgs(pContractBank, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQryContractBank(TraderSpi^ sender, RspQryContractBankArgs^ e)
	{
		this->RspQryContractBank(sender, e);
	}

	void TraderSpi::OnRspQryParkedOrder(ParkedOrderField^ pParkedOrder, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryParkedOrder(this, gcnew RspQryParkedOrderArgs(pParkedOrder, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQryParkedOrder(TraderSpi^ sender, RspQryParkedOrderArgs^ e)
	{
		this->RspQryParkedOrder(sender, e);
	}

	void TraderSpi::OnRspQryParkedOrderAction(ParkedOrderActionField^ pParkedOrderAction, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryParkedOrderAction(this, gcnew RspQryParkedOrderActionArgs(pParkedOrderAction, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQryParkedOrderAction(TraderSpi^ sender, RspQryParkedOrderActionArgs^ e)
	{
		this->RspQryParkedOrderAction(sender, e);
	}

	void TraderSpi::OnRspQryTradingNotice(TradingNoticeField^ pTradingNotice, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryTradingNotice(this, gcnew RspQryTradingNoticeArgs(pTradingNotice, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQryTradingNotice(TraderSpi^ sender, RspQryTradingNoticeArgs^ e)
	{
		this->RspQryTradingNotice(sender, e);
	}

	void TraderSpi::OnRspQryBrokerTradingParams(BrokerTradingParamsField^ pBrokerTradingParams, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryBrokerTradingParams(this, gcnew RspQryBrokerTradingParamsArgs(pBrokerTradingParams, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQryBrokerTradingParams(TraderSpi^ sender, RspQryBrokerTradingParamsArgs^ e)
	{
		this->RspQryBrokerTradingParams(sender, e);
	}

	void TraderSpi::OnRspQryBrokerTradingAlgos(BrokerTradingAlgosField^ pBrokerTradingAlgos, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryBrokerTradingAlgos(this, gcnew RspQryBrokerTradingAlgosArgs(pBrokerTradingAlgos, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQryBrokerTradingAlgos(TraderSpi^ sender, RspQryBrokerTradingAlgosArgs^ e)
	{
		this->RspQryBrokerTradingAlgos(sender, e);
	}

	void TraderSpi::OnRspQueryCFMMCTradingAccountToken(QueryCFMMCTradingAccountTokenField^ pQueryCFMMCTradingAccountToken, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQueryCFMMCTradingAccountToken(this, gcnew RspQueryCFMMCTradingAccountTokenArgs(pQueryCFMMCTradingAccountToken, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQueryCFMMCTradingAccountToken(TraderSpi^ sender, RspQueryCFMMCTradingAccountTokenArgs^ e)
	{
		this->RspQueryCFMMCTradingAccountToken(sender, e);
	}

	void TraderSpi::OnRtnFromBankToFutureByBank(RspTransferField^ pRspTransfer)
	{
		this->RtnFromBankToFutureByBank(this, gcnew RtnFromBankToFutureByBankArgs(pRspTransfer));
	}

	void TraderSpi::OnRtnFromBankToFutureByBank(TraderSpi^ sender, RtnFromBankToFutureByBankArgs^ e)
	{
		this->RtnFromBankToFutureByBank(sender, e);
	}

	void TraderSpi::OnRtnFromFutureToBankByBank(RspTransferField^ pRspTransfer)
	{
		this->RtnFromFutureToBankByBank(this, gcnew RtnFromFutureToBankByBankArgs(pRspTransfer));
	}

	void TraderSpi::OnRtnFromFutureToBankByBank(TraderSpi^ sender, RtnFromFutureToBankByBankArgs^ e)
	{
		this->RtnFromFutureToBankByBank(sender, e);
	}

	void TraderSpi::OnRtnRepealFromBankToFutureByBank(RspRepealField^ pRspRepeal)
	{
		this->RtnRepealFromBankToFutureByBank(this, gcnew RtnRepealFromBankToFutureByBankArgs(pRspRepeal));
	}

	void TraderSpi::OnRtnRepealFromBankToFutureByBank(TraderSpi^ sender, RtnRepealFromBankToFutureByBankArgs^ e)
	{
		this->RtnRepealFromBankToFutureByBank(sender, e);
	}

	void TraderSpi::OnRtnRepealFromFutureToBankByBank(RspRepealField^ pRspRepeal)
	{
		this->RtnRepealFromFutureToBankByBank(this, gcnew RtnRepealFromFutureToBankByBankArgs(pRspRepeal));
	}

	void TraderSpi::OnRtnRepealFromFutureToBankByBank(TraderSpi^ sender, RtnRepealFromFutureToBankByBankArgs^ e)
	{
		this->RtnRepealFromFutureToBankByBank(sender, e);
	}

	void TraderSpi::OnRtnFromBankToFutureByFuture(RspTransferField^ pRspTransfer)
	{
		this->RtnFromBankToFutureByFuture(this, gcnew RtnFromBankToFutureByFutureArgs(pRspTransfer));
	}

	void TraderSpi::OnRtnFromBankToFutureByFuture(TraderSpi^ sender, RtnFromBankToFutureByFutureArgs^ e)
	{
		this->RtnFromBankToFutureByFuture(sender, e);
	}

	void TraderSpi::OnRtnFromFutureToBankByFuture(RspTransferField^ pRspTransfer)
	{
		this->RtnFromFutureToBankByFuture(this, gcnew RtnFromFutureToBankByFutureArgs(pRspTransfer));
	}

	void TraderSpi::OnRtnFromFutureToBankByFuture(TraderSpi^ sender, RtnFromFutureToBankByFutureArgs^ e)
	{
		this->RtnFromFutureToBankByFuture(sender, e);
	}

	void TraderSpi::OnRtnRepealFromBankToFutureByFutureManual(RspRepealField^ pRspRepeal)
	{
		this->RtnRepealFromBankToFutureByFutureManual(this, gcnew RtnRepealFromBankToFutureByFutureManualArgs(pRspRepeal));
	}

	void TraderSpi::OnRtnRepealFromBankToFutureByFutureManual(TraderSpi^ sender, RtnRepealFromBankToFutureByFutureManualArgs^ e)
	{
		this->RtnRepealFromBankToFutureByFutureManual(sender, e);
	}

	void TraderSpi::OnRtnRepealFromFutureToBankByFutureManual(RspRepealField^ pRspRepeal)
	{
		this->RtnRepealFromFutureToBankByFutureManual(this, gcnew RtnRepealFromFutureToBankByFutureManualArgs(pRspRepeal));
	}

	void TraderSpi::OnRtnRepealFromFutureToBankByFutureManual(TraderSpi^ sender, RtnRepealFromFutureToBankByFutureManualArgs^ e)
	{
		this->RtnRepealFromFutureToBankByFutureManual(sender, e);
	}

	void TraderSpi::OnRtnQueryBankBalanceByFuture(NotifyQueryAccountField^ pNotifyQueryAccount)
	{
		this->RtnQueryBankBalanceByFuture(this, gcnew RtnQueryBankBalanceByFutureArgs(pNotifyQueryAccount));
	}

	void TraderSpi::OnRtnQueryBankBalanceByFuture(TraderSpi^ sender, RtnQueryBankBalanceByFutureArgs^ e)
	{
		this->RtnQueryBankBalanceByFuture(sender, e);
	}

	void TraderSpi::OnErrRtnBankToFutureByFuture(ReqTransferField^ pReqTransfer, RspInfoField^ pRspInfo)
	{
		this->ErrRtnBankToFutureByFuture(this, gcnew ErrRtnBankToFutureByFutureArgs(pReqTransfer, pRspInfo));
	}

	void TraderSpi::OnErrRtnBankToFutureByFuture(TraderSpi^ sender, ErrRtnBankToFutureByFutureArgs^ e)
	{
		this->ErrRtnBankToFutureByFuture(sender, e);
	}

	void TraderSpi::OnErrRtnFutureToBankByFuture(ReqTransferField^ pReqTransfer, RspInfoField^ pRspInfo)
	{
		this->ErrRtnFutureToBankByFuture(this, gcnew ErrRtnFutureToBankByFutureArgs(pReqTransfer, pRspInfo));
	}

	void TraderSpi::OnErrRtnFutureToBankByFuture(TraderSpi^ sender, ErrRtnFutureToBankByFutureArgs^ e)
	{
		this->ErrRtnFutureToBankByFuture(sender, e);
	}

	void TraderSpi::OnErrRtnRepealBankToFutureByFutureManual(ReqRepealField^ pReqRepeal, RspInfoField^ pRspInfo)
	{
		this->ErrRtnRepealBankToFutureByFutureManual(this, gcnew ErrRtnRepealBankToFutureByFutureManualArgs(pReqRepeal, pRspInfo));
	}

	void TraderSpi::OnErrRtnRepealBankToFutureByFutureManual(TraderSpi^ sender, ErrRtnRepealBankToFutureByFutureManualArgs^ e)
	{
		this->ErrRtnRepealBankToFutureByFutureManual(sender, e);
	}

	void TraderSpi::OnErrRtnRepealFutureToBankByFutureManual(ReqRepealField^ pReqRepeal, RspInfoField^ pRspInfo)
	{
		this->ErrRtnRepealFutureToBankByFutureManual(this, gcnew ErrRtnRepealFutureToBankByFutureManualArgs(pReqRepeal, pRspInfo));
	}

	void TraderSpi::OnErrRtnRepealFutureToBankByFutureManual(TraderSpi^ sender, ErrRtnRepealFutureToBankByFutureManualArgs^ e)
	{
		this->ErrRtnRepealFutureToBankByFutureManual(sender, e);
	}

	void TraderSpi::OnErrRtnQueryBankBalanceByFuture(ReqQueryAccountField^ pReqQueryAccount, RspInfoField^ pRspInfo)
	{
		this->ErrRtnQueryBankBalanceByFuture(this, gcnew ErrRtnQueryBankBalanceByFutureArgs(pReqQueryAccount, pRspInfo));
	}

	void TraderSpi::OnErrRtnQueryBankBalanceByFuture(TraderSpi^ sender, ErrRtnQueryBankBalanceByFutureArgs^ e)
	{
		this->ErrRtnQueryBankBalanceByFuture(sender, e);
	}

	void TraderSpi::OnRtnRepealFromBankToFutureByFuture(RspRepealField^ pRspRepeal)
	{
		this->RtnRepealFromBankToFutureByFuture(this, gcnew RtnRepealFromBankToFutureByFutureArgs(pRspRepeal));
	}

	void TraderSpi::OnRtnRepealFromBankToFutureByFuture(TraderSpi^ sender, RtnRepealFromBankToFutureByFutureArgs^ e)
	{
		this->RtnRepealFromBankToFutureByFuture(sender, e);
	}

	void TraderSpi::OnRtnRepealFromFutureToBankByFuture(RspRepealField^ pRspRepeal)
	{
		this->RtnRepealFromFutureToBankByFuture(this, gcnew RtnRepealFromFutureToBankByFutureArgs(pRspRepeal));
	}

	void TraderSpi::OnRtnRepealFromFutureToBankByFuture(TraderSpi^ sender, RtnRepealFromFutureToBankByFutureArgs^ e)
	{
		this->RtnRepealFromFutureToBankByFuture(sender, e);
	}

	void TraderSpi::OnRspFromBankToFutureByFuture(ReqTransferField^ pReqTransfer, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspFromBankToFutureByFuture(this, gcnew RspFromBankToFutureByFutureArgs(pReqTransfer, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspFromBankToFutureByFuture(TraderSpi^ sender, RspFromBankToFutureByFutureArgs^ e)
	{
		this->RspFromBankToFutureByFuture(sender, e);
	}

	void TraderSpi::OnRspFromFutureToBankByFuture(ReqTransferField^ pReqTransfer, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspFromFutureToBankByFuture(this, gcnew RspFromFutureToBankByFutureArgs(pReqTransfer, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspFromFutureToBankByFuture(TraderSpi^ sender, RspFromFutureToBankByFutureArgs^ e)
	{
		this->RspFromFutureToBankByFuture(sender, e);
	}

	void TraderSpi::OnRspQueryBankAccountMoneyByFuture(ReqQueryAccountField^ pReqQueryAccount, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQueryBankAccountMoneyByFuture(this, gcnew RspQueryBankAccountMoneyByFutureArgs(pReqQueryAccount, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQueryBankAccountMoneyByFuture(TraderSpi^ sender, RspQueryBankAccountMoneyByFutureArgs^ e)
	{
		this->RspQueryBankAccountMoneyByFuture(sender, e);
	}

	void TraderSpi::OnRtnOpenAccountByBank(OpenAccountField^ pOpenAccount)
	{
		this->RtnOpenAccountByBank(this, gcnew RtnOpenAccountByBankArgs(pOpenAccount));
	}

	void TraderSpi::OnRtnOpenAccountByBank(TraderSpi^ sender, RtnOpenAccountByBankArgs^ e)
	{
		this->RtnOpenAccountByBank(sender, e);
	}

	void TraderSpi::OnRtnCancelAccountByBank(CancelAccountField^ pCancelAccount)
	{
		this->RtnCancelAccountByBank(this, gcnew RtnCancelAccountByBankArgs(pCancelAccount));
	}

	void TraderSpi::OnRtnCancelAccountByBank(TraderSpi^ sender, RtnCancelAccountByBankArgs^ e)
	{
		this->RtnCancelAccountByBank(sender, e);
	}

	void TraderSpi::OnRtnChangeAccountByBank(ChangeAccountField^ pChangeAccount)
	{
		this->RtnChangeAccountByBank(this, gcnew RtnChangeAccountByBankArgs(pChangeAccount));
	}

	void TraderSpi::OnRtnChangeAccountByBank(TraderSpi^ sender, RtnChangeAccountByBankArgs^ e)
	{
		this->RtnChangeAccountByBank(sender, e);
	}

	void TraderSpi::OnRspQryClassifiedInstrument(InstrumentField^ pInstrument, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryClassifiedInstrument(this, gcnew RspQryClassifiedInstrumentArgs(pInstrument, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQryClassifiedInstrument(TraderSpi^ sender, RspQryClassifiedInstrumentArgs^ e)
	{
		this->RspQryClassifiedInstrument(sender, e);
	}

	void TraderSpi::OnRspQryCombPromotionParam(CombPromotionParamField^ pCombPromotionParam, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryCombPromotionParam(this, gcnew RspQryCombPromotionParamArgs(pCombPromotionParam, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQryCombPromotionParam(TraderSpi^ sender, RspQryCombPromotionParamArgs^ e)
	{
		this->RspQryCombPromotionParam(sender, e);
	}

	void TraderSpi::OnRspQryRiskSettleInvstPosition(RiskSettleInvstPositionField^ pRiskSettleInvstPosition, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryRiskSettleInvstPosition(this, gcnew RspQryRiskSettleInvstPositionArgs(pRiskSettleInvstPosition, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQryRiskSettleInvstPosition(TraderSpi^ sender, RspQryRiskSettleInvstPositionArgs^ e)
	{
		this->RspQryRiskSettleInvstPosition(sender, e);
	}

	void TraderSpi::OnRspQryRiskSettleProductStatus(RiskSettleProductStatusField^ pRiskSettleProductStatus, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
	{
		this->RspQryRiskSettleProductStatus(this, gcnew RspQryRiskSettleProductStatusArgs(pRiskSettleProductStatus, pRspInfo, nRequestID, bIsLast));
	}

	void TraderSpi::OnRspQryRiskSettleProductStatus(TraderSpi^ sender, RspQryRiskSettleProductStatusArgs^ e)
	{
		this->RspQryRiskSettleProductStatus(sender, e);
	}


}
