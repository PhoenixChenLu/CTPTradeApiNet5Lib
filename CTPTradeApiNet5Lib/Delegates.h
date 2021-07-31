#pragma onces
#include "EventArgsClasses.h"

namespace PhoenixCTP
{
	ref class MdSpi;
	
	/// <summary>
	/// Md部分
	/// </summary>	
	namespace MdDelegates
	{		
		/// <summary>
		/// 客户端与交易后台建立通信连接时的委托
		/// </summary>
		public delegate void DOnFrontConnected(MdSpi^ sender, FrontConnectedArgs^ e);

		/// <summary>
		/// 客户端与后台通信连接断开时的委托
		/// </summary>
		public delegate void DOnFrontDisconnected(MdSpi^ sender, FrontDisconnectedArgs^ e);

		/// <summary>
		/// 心跳超时警告的委托
		/// </summary>
		public delegate void DOnHeartBeatWarning(MdSpi^ sender, HeartBeatWarningArgs^ e);

		/// <summary>
		/// 登录请求响应的委托
		/// </summary>
		public delegate void DOnRspUserLogin(MdSpi^ sender, RspUserLoginArgs^ e);

		/// <summary>
		/// 登出请求响应的委托
		/// </summary>
		public delegate void DOnRspUserLogout(MdSpi^ sender, RspUserLogoutArgs^ e);

		/// <summary>
		/// 请求查询组播合约响应的委托
		/// </summary>
		public delegate void DOnRspQryMulticastInstrument(MdSpi^ sender, RspQryMulticastInstrumentArgs^ e);

		/// <summary>
		/// 错误应答的委托
		/// </summary>
		public delegate void DOnRspError(MdSpi^ sender, RspErrorArgs^ e);

		/// <summary>
		/// 订阅行情应答的委托
		/// </summary>
		public delegate void DOnRspSubMarketData(MdSpi^ sender, SpecificInstrumentEventArgs^ e);

		/// <summary>
		/// 取消订阅行情应答的委托
		/// </summary>
		public delegate void DOnRspUnSubMarketData(MdSpi^ sender, SpecificInstrumentEventArgs^ e);

		/// <summary>
		/// 订阅询价应答的委托
		/// </summary>
		public delegate void DOnRspSubForQuoteRsp(MdSpi^ sender, SpecificInstrumentEventArgs^ e);

		/// <summary>
		/// 取消订阅询价应答的委托
		/// </summary>
		public delegate void DOnRspUnSubForQuoteRsp(MdSpi^ sender, SpecificInstrumentEventArgs^ e);

		/// <summary>
		/// 深度行情通知的委托
		/// </summary>
		public delegate void DOnRtnDepthMarketData(MdSpi^ sender, RtnDepthMarketDataArgs^ e);

		/// <summary>
		/// 询价通知的委托
		/// </summary>
		public delegate void DOnRtnForQuoteRsp(MdSpi^ sender, RtnForQuoteRspArgs^ e);
	}

	
	ref class TraderSpi;
	
	/// <summary>
	/// Trader部分
	/// </summary>
	namespace TraderDelegates
	{
		
		/// <summary>
		/// 客户端与交易后台建立起通信连接时的委托
		/// </summary>
		public delegate void DOnFrontConnected(TraderSpi^ sender, FrontConnectedArgs^ e);

		/// <summary>
		/// 0x2003 收到错误报文的委托
		/// </summary>
		public delegate void DOnFrontDisconnected(TraderSpi^ sender, FrontDisconnectedArgs^ e);

		/// <summary>
		/// @param nTimeLapse 距离上次接收报文的时间的委托
		/// </summary>
		public delegate void DOnHeartBeatWarning(TraderSpi^ sender, HeartBeatWarningArgs^ e);

		/// <summary>
		/// 客户端认证响应的委托
		/// </summary>
		public delegate void DOnRspAuthenticate(TraderSpi^ sender, RspAuthenticateArgs^ e);

		/// <summary>
		/// 登录请求响应的委托
		/// </summary>
		public delegate void DOnRspUserLogin(TraderSpi^ sender, RspUserLoginArgs^ e);

		/// <summary>
		/// 登出请求响应的委托
		/// </summary>
		public delegate void DOnRspUserLogout(TraderSpi^ sender, RspUserLogoutArgs^ e);

		/// <summary>
		/// 用户口令更新请求响应的委托
		/// </summary>
		public delegate void DOnRspUserPasswordUpdate(TraderSpi^ sender, RspUserPasswordUpdateArgs^ e);

		/// <summary>
		/// 资金账户口令更新请求响应的委托
		/// </summary>
		public delegate void DOnRspTradingAccountPasswordUpdate(TraderSpi^ sender, RspTradingAccountPasswordUpdateArgs^ e);

		/// <summary>
		/// 查询用户当前支持的认证模式的回复的委托
		/// </summary>
		public delegate void DOnRspUserAuthMethod(TraderSpi^ sender, RspUserAuthMethodArgs^ e);

		/// <summary>
		/// 获取图形验证码请求的回复的委托
		/// </summary>
		public delegate void DOnRspGenUserCaptcha(TraderSpi^ sender, RspGenUserCaptchaArgs^ e);

		/// <summary>
		/// 获取短信验证码请求的回复的委托
		/// </summary>
		public delegate void DOnRspGenUserText(TraderSpi^ sender, RspGenUserTextArgs^ e);

		/// <summary>
		/// 报单录入请求响应的委托
		/// </summary>
		public delegate void DOnRspOrderInsert(TraderSpi^ sender, RspOrderInsertArgs^ e);

		/// <summary>
		/// 预埋单录入请求响应的委托
		/// </summary>
		public delegate void DOnRspParkedOrderInsert(TraderSpi^ sender, RspParkedOrderInsertArgs^ e);

		/// <summary>
		/// 预埋撤单录入请求响应的委托
		/// </summary>
		public delegate void DOnRspParkedOrderAction(TraderSpi^ sender, RspParkedOrderActionArgs^ e);

		/// <summary>
		/// 报单操作请求响应的委托
		/// </summary>
		public delegate void DOnRspOrderAction(TraderSpi^ sender, RspOrderActionArgs^ e);

		/// <summary>
		/// 查询最大报单数量响应的委托
		/// </summary>
		public delegate void DOnRspQryMaxOrderVolume(TraderSpi^ sender, RspQryMaxOrderVolumeArgs^ e);

		/// <summary>
		/// 投资者结算结果确认响应的委托
		/// </summary>
		public delegate void DOnRspSettlementInfoConfirm(TraderSpi^ sender, RspSettlementInfoConfirmArgs^ e);

		/// <summary>
		/// 删除预埋单响应的委托
		/// </summary>
		public delegate void DOnRspRemoveParkedOrder(TraderSpi^ sender, RspRemoveParkedOrderArgs^ e);

		/// <summary>
		/// 删除预埋撤单响应的委托
		/// </summary>
		public delegate void DOnRspRemoveParkedOrderAction(TraderSpi^ sender, RspRemoveParkedOrderActionArgs^ e);

		/// <summary>
		/// 执行宣告录入请求响应的委托
		/// </summary>
		public delegate void DOnRspExecOrderInsert(TraderSpi^ sender, RspExecOrderInsertArgs^ e);

		/// <summary>
		/// 执行宣告操作请求响应的委托
		/// </summary>
		public delegate void DOnRspExecOrderAction(TraderSpi^ sender, RspExecOrderActionArgs^ e);

		/// <summary>
		/// 询价录入请求响应的委托
		/// </summary>
		public delegate void DOnRspForQuoteInsert(TraderSpi^ sender, RspForQuoteInsertArgs^ e);

		/// <summary>
		/// 报价录入请求响应的委托
		/// </summary>
		public delegate void DOnRspQuoteInsert(TraderSpi^ sender, RspQuoteInsertArgs^ e);

		/// <summary>
		/// 报价操作请求响应的委托
		/// </summary>
		public delegate void DOnRspQuoteAction(TraderSpi^ sender, RspQuoteActionArgs^ e);

		/// <summary>
		/// 批量报单操作请求响应的委托
		/// </summary>
		public delegate void DOnRspBatchOrderAction(TraderSpi^ sender, RspBatchOrderActionArgs^ e);

		/// <summary>
		/// 期权自对冲录入请求响应的委托
		/// </summary>
		public delegate void DOnRspOptionSelfCloseInsert(TraderSpi^ sender, RspOptionSelfCloseInsertArgs^ e);

		/// <summary>
		/// 期权自对冲操作请求响应的委托
		/// </summary>
		public delegate void DOnRspOptionSelfCloseAction(TraderSpi^ sender, RspOptionSelfCloseActionArgs^ e);

		/// <summary>
		/// 申请组合录入请求响应的委托
		/// </summary>
		public delegate void DOnRspCombActionInsert(TraderSpi^ sender, RspCombActionInsertArgs^ e);

		/// <summary>
		/// 请求查询报单响应的委托
		/// </summary>
		public delegate void DOnRspQryOrder(TraderSpi^ sender, RspQryOrderArgs^ e);

		/// <summary>
		/// 请求查询成交响应的委托
		/// </summary>
		public delegate void DOnRspQryTrade(TraderSpi^ sender, RspQryTradeArgs^ e);

		/// <summary>
		/// 请求查询投资者持仓响应的委托
		/// </summary>
		public delegate void DOnRspQryInvestorPosition(TraderSpi^ sender, RspQryInvestorPositionArgs^ e);

		/// <summary>
		/// 请求查询资金账户响应的委托
		/// </summary>
		public delegate void DOnRspQryTradingAccount(TraderSpi^ sender, RspQryTradingAccountArgs^ e);

		/// <summary>
		/// 请求查询投资者响应的委托
		/// </summary>
		public delegate void DOnRspQryInvestor(TraderSpi^ sender, RspQryInvestorArgs^ e);

		/// <summary>
		/// 请求查询交易编码响应的委托
		/// </summary>
		public delegate void DOnRspQryTradingCode(TraderSpi^ sender, RspQryTradingCodeArgs^ e);

		/// <summary>
		/// 请求查询合约保证金率响应的委托
		/// </summary>
		public delegate void DOnRspQryInstrumentMarginRate(TraderSpi^ sender, RspQryInstrumentMarginRateArgs^ e);

		/// <summary>
		/// 请求查询合约手续费率响应的委托
		/// </summary>
		public delegate void DOnRspQryInstrumentCommissionRate(TraderSpi^ sender, RspQryInstrumentCommissionRateArgs^ e);

		/// <summary>
		/// 请求查询交易所响应的委托
		/// </summary>
		public delegate void DOnRspQryExchange(TraderSpi^ sender, RspQryExchangeArgs^ e);

		/// <summary>
		/// 请求查询产品响应的委托
		/// </summary>
		public delegate void DOnRspQryProduct(TraderSpi^ sender, RspQryProductArgs^ e);

		/// <summary>
		/// 请求查询合约响应的委托
		/// </summary>
		public delegate void DOnRspQryInstrument(TraderSpi^ sender, RspQryInstrumentArgs^ e);

		/// <summary>
		/// 请求查询行情响应的委托
		/// </summary>
		public delegate void DOnRspQryDepthMarketData(TraderSpi^ sender, RspQryDepthMarketDataArgs^ e);

		/// <summary>
		/// 请求查询投资者结算结果响应的委托
		/// </summary>
		public delegate void DOnRspQrySettlementInfo(TraderSpi^ sender, RspQrySettlementInfoArgs^ e);

		/// <summary>
		/// 请求查询转帐银行响应的委托
		/// </summary>
		public delegate void DOnRspQryTransferBank(TraderSpi^ sender, RspQryTransferBankArgs^ e);

		/// <summary>
		/// 请求查询投资者持仓明细响应的委托
		/// </summary>
		public delegate void DOnRspQryInvestorPositionDetail(TraderSpi^ sender, RspQryInvestorPositionDetailArgs^ e);

		/// <summary>
		/// 请求查询客户通知响应的委托
		/// </summary>
		public delegate void DOnRspQryNotice(TraderSpi^ sender, RspQryNoticeArgs^ e);

		/// <summary>
		/// 请求查询结算信息确认响应的委托
		/// </summary>
		public delegate void DOnRspQrySettlementInfoConfirm(TraderSpi^ sender, RspQrySettlementInfoConfirmArgs^ e);

		/// <summary>
		/// 请求查询投资者持仓明细响应的委托
		/// </summary>
		public delegate void DOnRspQryInvestorPositionCombineDetail(TraderSpi^ sender, RspQryInvestorPositionCombineDetailArgs^ e);

		/// <summary>
		/// 查询保证金监管系统经纪公司资金账户密钥响应的委托
		/// </summary>
		public delegate void DOnRspQryCFMMCTradingAccountKey(TraderSpi^ sender, RspQryCFMMCTradingAccountKeyArgs^ e);

		/// <summary>
		/// 请求查询仓单折抵信息响应的委托
		/// </summary>
		public delegate void DOnRspQryEWarrantOffset(TraderSpi^ sender, RspQryEWarrantOffsetArgs^ e);

		/// <summary>
		/// 请求查询投资者品种跨品种保证金响应的委托
		/// </summary>
		public delegate void DOnRspQryInvestorProductGroupMargin(TraderSpi^ sender, RspQryInvestorProductGroupMarginArgs^ e);

		/// <summary>
		/// 请求查询交易所保证金率响应的委托
		/// </summary>
		public delegate void DOnRspQryExchangeMarginRate(TraderSpi^ sender, RspQryExchangeMarginRateArgs^ e);

		/// <summary>
		/// 请求查询交易所调整保证金率响应的委托
		/// </summary>
		public delegate void DOnRspQryExchangeMarginRateAdjust(TraderSpi^ sender, RspQryExchangeMarginRateAdjustArgs^ e);

		/// <summary>
		/// 请求查询汇率响应的委托
		/// </summary>
		public delegate void DOnRspQryExchangeRate(TraderSpi^ sender, RspQryExchangeRateArgs^ e);

		/// <summary>
		/// 请求查询二级代理操作员银期权限响应的委托
		/// </summary>
		public delegate void DOnRspQrySecAgentACIDMap(TraderSpi^ sender, RspQrySecAgentACIDMapArgs^ e);

		/// <summary>
		/// 请求查询产品报价汇率的委托
		/// </summary>
		public delegate void DOnRspQryProductExchRate(TraderSpi^ sender, RspQryProductExchRateArgs^ e);

		/// <summary>
		/// 请求查询产品组的委托
		/// </summary>
		public delegate void DOnRspQryProductGroup(TraderSpi^ sender, RspQryProductGroupArgs^ e);

		/// <summary>
		/// 请求查询做市商合约手续费率响应的委托
		/// </summary>
		public delegate void DOnRspQryMMInstrumentCommissionRate(TraderSpi^ sender, RspQryMMInstrumentCommissionRateArgs^ e);

		/// <summary>
		/// 请求查询做市商期权合约手续费响应的委托
		/// </summary>
		public delegate void DOnRspQryMMOptionInstrCommRate(TraderSpi^ sender, RspQryMMOptionInstrCommRateArgs^ e);

		/// <summary>
		/// 请求查询报单手续费响应的委托
		/// </summary>
		public delegate void DOnRspQryInstrumentOrderCommRate(TraderSpi^ sender, RspQryInstrumentOrderCommRateArgs^ e);

		/// <summary>
		/// 请求查询资金账户响应的委托
		/// </summary>
		public delegate void DOnRspQrySecAgentTradingAccount(TraderSpi^ sender, RspQrySecAgentTradingAccountArgs^ e);

		/// <summary>
		/// 请求查询二级代理商资金校验模式响应的委托
		/// </summary>
		public delegate void DOnRspQrySecAgentCheckMode(TraderSpi^ sender, RspQrySecAgentCheckModeArgs^ e);

		/// <summary>
		/// 请求查询二级代理商信息响应的委托
		/// </summary>
		public delegate void DOnRspQrySecAgentTradeInfo(TraderSpi^ sender, RspQrySecAgentTradeInfoArgs^ e);

		/// <summary>
		/// 请求查询期权交易成本响应的委托
		/// </summary>
		public delegate void DOnRspQryOptionInstrTradeCost(TraderSpi^ sender, RspQryOptionInstrTradeCostArgs^ e);

		/// <summary>
		/// 请求查询期权合约手续费响应的委托
		/// </summary>
		public delegate void DOnRspQryOptionInstrCommRate(TraderSpi^ sender, RspQryOptionInstrCommRateArgs^ e);

		/// <summary>
		/// 请求查询执行宣告响应的委托
		/// </summary>
		public delegate void DOnRspQryExecOrder(TraderSpi^ sender, RspQryExecOrderArgs^ e);

		/// <summary>
		/// 请求查询询价响应的委托
		/// </summary>
		public delegate void DOnRspQryForQuote(TraderSpi^ sender, RspQryForQuoteArgs^ e);

		/// <summary>
		/// 请求查询报价响应的委托
		/// </summary>
		public delegate void DOnRspQryQuote(TraderSpi^ sender, RspQryQuoteArgs^ e);

		/// <summary>
		/// 请求查询期权自对冲响应的委托
		/// </summary>
		public delegate void DOnRspQryOptionSelfClose(TraderSpi^ sender, RspQryOptionSelfCloseArgs^ e);

		/// <summary>
		/// 请求查询投资单元响应的委托
		/// </summary>
		public delegate void DOnRspQryInvestUnit(TraderSpi^ sender, RspQryInvestUnitArgs^ e);

		/// <summary>
		/// 请求查询组合合约安全系数响应的委托
		/// </summary>
		public delegate void DOnRspQryCombInstrumentGuard(TraderSpi^ sender, RspQryCombInstrumentGuardArgs^ e);

		/// <summary>
		/// 请求查询申请组合响应的委托
		/// </summary>
		public delegate void DOnRspQryCombAction(TraderSpi^ sender, RspQryCombActionArgs^ e);

		/// <summary>
		/// 请求查询转帐流水响应的委托
		/// </summary>
		public delegate void DOnRspQryTransferSerial(TraderSpi^ sender, RspQryTransferSerialArgs^ e);

		/// <summary>
		/// 请求查询银期签约关系响应的委托
		/// </summary>
		public delegate void DOnRspQryAccountregister(TraderSpi^ sender, RspQryAccountregisterArgs^ e);

		/// <summary>
		/// 错误应答的委托
		/// </summary>
		public delegate void DOnRspError(TraderSpi^ sender, RspErrorArgs^ e);

		/// <summary>
		/// 报单通知的委托
		/// </summary>
		public delegate void DOnRtnOrder(TraderSpi^ sender, RtnOrderArgs^ e);

		/// <summary>
		/// 成交通知的委托
		/// </summary>
		public delegate void DOnRtnTrade(TraderSpi^ sender, RtnTradeArgs^ e);

		/// <summary>
		/// 报单录入错误回报的委托
		/// </summary>
		public delegate void DOnErrRtnOrderInsert(TraderSpi^ sender, ErrRtnOrderInsertArgs^ e);

		/// <summary>
		/// 报单操作错误回报的委托
		/// </summary>
		public delegate void DOnErrRtnOrderAction(TraderSpi^ sender, ErrRtnOrderActionArgs^ e);

		/// <summary>
		/// 合约交易状态通知的委托
		/// </summary>
		public delegate void DOnRtnInstrumentStatus(TraderSpi^ sender, RtnInstrumentStatusArgs^ e);

		/// <summary>
		/// 交易所公告通知的委托
		/// </summary>
		public delegate void DOnRtnBulletin(TraderSpi^ sender, RtnBulletinArgs^ e);

		/// <summary>
		/// 交易通知的委托
		/// </summary>
		public delegate void DOnRtnTradingNotice(TraderSpi^ sender, RtnTradingNoticeArgs^ e);

		/// <summary>
		/// 提示条件单校验错误的委托
		/// </summary>
		public delegate void DOnRtnErrorConditionalOrder(TraderSpi^ sender, RtnErrorConditionalOrderArgs^ e);

		/// <summary>
		/// 执行宣告通知的委托
		/// </summary>
		public delegate void DOnRtnExecOrder(TraderSpi^ sender, RtnExecOrderArgs^ e);

		/// <summary>
		/// 执行宣告录入错误回报的委托
		/// </summary>
		public delegate void DOnErrRtnExecOrderInsert(TraderSpi^ sender, ErrRtnExecOrderInsertArgs^ e);

		/// <summary>
		/// 执行宣告操作错误回报的委托
		/// </summary>
		public delegate void DOnErrRtnExecOrderAction(TraderSpi^ sender, ErrRtnExecOrderActionArgs^ e);

		/// <summary>
		/// 询价录入错误回报的委托
		/// </summary>
		public delegate void DOnErrRtnForQuoteInsert(TraderSpi^ sender, ErrRtnForQuoteInsertArgs^ e);

		/// <summary>
		/// 报价通知的委托
		/// </summary>
		public delegate void DOnRtnQuote(TraderSpi^ sender, RtnQuoteArgs^ e);

		/// <summary>
		/// 报价录入错误回报的委托
		/// </summary>
		public delegate void DOnErrRtnQuoteInsert(TraderSpi^ sender, ErrRtnQuoteInsertArgs^ e);

		/// <summary>
		/// 报价操作错误回报的委托
		/// </summary>
		public delegate void DOnErrRtnQuoteAction(TraderSpi^ sender, ErrRtnQuoteActionArgs^ e);

		/// <summary>
		/// 询价通知的委托
		/// </summary>
		public delegate void DOnRtnForQuoteRsp(TraderSpi^ sender, RtnForQuoteRspArgs^ e);

		/// <summary>
		/// 保证金监控中心用户令牌的委托
		/// </summary>
		public delegate void DOnRtnCFMMCTradingAccountToken(TraderSpi^ sender, RtnCFMMCTradingAccountTokenArgs^ e);

		/// <summary>
		/// 批量报单操作错误回报的委托
		/// </summary>
		public delegate void DOnErrRtnBatchOrderAction(TraderSpi^ sender, ErrRtnBatchOrderActionArgs^ e);

		/// <summary>
		/// 期权自对冲通知的委托
		/// </summary>
		public delegate void DOnRtnOptionSelfClose(TraderSpi^ sender, RtnOptionSelfCloseArgs^ e);

		/// <summary>
		/// 期权自对冲录入错误回报的委托
		/// </summary>
		public delegate void DOnErrRtnOptionSelfCloseInsert(TraderSpi^ sender, ErrRtnOptionSelfCloseInsertArgs^ e);

		/// <summary>
		/// 期权自对冲操作错误回报的委托
		/// </summary>
		public delegate void DOnErrRtnOptionSelfCloseAction(TraderSpi^ sender, ErrRtnOptionSelfCloseActionArgs^ e);

		/// <summary>
		/// 申请组合通知的委托
		/// </summary>
		public delegate void DOnRtnCombAction(TraderSpi^ sender, RtnCombActionArgs^ e);

		/// <summary>
		/// 申请组合录入错误回报的委托
		/// </summary>
		public delegate void DOnErrRtnCombActionInsert(TraderSpi^ sender, ErrRtnCombActionInsertArgs^ e);

		/// <summary>
		/// 请求查询签约银行响应的委托
		/// </summary>
		public delegate void DOnRspQryContractBank(TraderSpi^ sender, RspQryContractBankArgs^ e);

		/// <summary>
		/// 请求查询预埋单响应的委托
		/// </summary>
		public delegate void DOnRspQryParkedOrder(TraderSpi^ sender, RspQryParkedOrderArgs^ e);

		/// <summary>
		/// 请求查询预埋撤单响应的委托
		/// </summary>
		public delegate void DOnRspQryParkedOrderAction(TraderSpi^ sender, RspQryParkedOrderActionArgs^ e);

		/// <summary>
		/// 请求查询交易通知响应的委托
		/// </summary>
		public delegate void DOnRspQryTradingNotice(TraderSpi^ sender, RspQryTradingNoticeArgs^ e);

		/// <summary>
		/// 请求查询经纪公司交易参数响应的委托
		/// </summary>
		public delegate void DOnRspQryBrokerTradingParams(TraderSpi^ sender, RspQryBrokerTradingParamsArgs^ e);

		/// <summary>
		/// 请求查询经纪公司交易算法响应的委托
		/// </summary>
		public delegate void DOnRspQryBrokerTradingAlgos(TraderSpi^ sender, RspQryBrokerTradingAlgosArgs^ e);

		/// <summary>
		/// 请求查询监控中心用户令牌的委托
		/// </summary>
		public delegate void DOnRspQueryCFMMCTradingAccountToken(TraderSpi^ sender, RspQueryCFMMCTradingAccountTokenArgs^ e);

		/// <summary>
		/// 银行发起银行资金转期货通知的委托
		/// </summary>
		public delegate void DOnRtnFromBankToFutureByBank(TraderSpi^ sender, RtnFromBankToFutureByBankArgs^ e);

		/// <summary>
		/// 银行发起期货资金转银行通知的委托
		/// </summary>
		public delegate void DOnRtnFromFutureToBankByBank(TraderSpi^ sender, RtnFromFutureToBankByBankArgs^ e);

		/// <summary>
		/// 银行发起冲正银行转期货通知的委托
		/// </summary>
		public delegate void DOnRtnRepealFromBankToFutureByBank(TraderSpi^ sender, RtnRepealFromBankToFutureByBankArgs^ e);

		/// <summary>
		/// 银行发起冲正期货转银行通知的委托
		/// </summary>
		public delegate void DOnRtnRepealFromFutureToBankByBank(TraderSpi^ sender, RtnRepealFromFutureToBankByBankArgs^ e);

		/// <summary>
		/// 期货发起银行资金转期货通知的委托
		/// </summary>
		public delegate void DOnRtnFromBankToFutureByFuture(TraderSpi^ sender, RtnFromBankToFutureByFutureArgs^ e);

		/// <summary>
		/// 期货发起期货资金转银行通知的委托
		/// </summary>
		public delegate void DOnRtnFromFutureToBankByFuture(TraderSpi^ sender, RtnFromFutureToBankByFutureArgs^ e);

		/// <summary>
		/// 系统运行时期货端手工发起冲正银行转期货请求，银行处理完毕后报盘发回的通知的委托
		/// </summary>
		public delegate void DOnRtnRepealFromBankToFutureByFutureManual(TraderSpi^ sender, RtnRepealFromBankToFutureByFutureManualArgs^ e);

		/// <summary>
		/// 系统运行时期货端手工发起冲正期货转银行请求，银行处理完毕后报盘发回的通知的委托
		/// </summary>
		public delegate void DOnRtnRepealFromFutureToBankByFutureManual(TraderSpi^ sender, RtnRepealFromFutureToBankByFutureManualArgs^ e);

		/// <summary>
		/// 期货发起查询银行余额通知的委托
		/// </summary>
		public delegate void DOnRtnQueryBankBalanceByFuture(TraderSpi^ sender, RtnQueryBankBalanceByFutureArgs^ e);

		/// <summary>
		/// 期货发起银行资金转期货错误回报的委托
		/// </summary>
		public delegate void DOnErrRtnBankToFutureByFuture(TraderSpi^ sender, ErrRtnBankToFutureByFutureArgs^ e);

		/// <summary>
		/// 期货发起期货资金转银行错误回报的委托
		/// </summary>
		public delegate void DOnErrRtnFutureToBankByFuture(TraderSpi^ sender, ErrRtnFutureToBankByFutureArgs^ e);

		/// <summary>
		/// 系统运行时期货端手工发起冲正银行转期货错误回报的委托
		/// </summary>
		public delegate void DOnErrRtnRepealBankToFutureByFutureManual(TraderSpi^ sender, ErrRtnRepealBankToFutureByFutureManualArgs^ e);

		/// <summary>
		/// 系统运行时期货端手工发起冲正期货转银行错误回报的委托
		/// </summary>
		public delegate void DOnErrRtnRepealFutureToBankByFutureManual(TraderSpi^ sender, ErrRtnRepealFutureToBankByFutureManualArgs^ e);

		/// <summary>
		/// 期货发起查询银行余额错误回报的委托
		/// </summary>
		public delegate void DOnErrRtnQueryBankBalanceByFuture(TraderSpi^ sender, ErrRtnQueryBankBalanceByFutureArgs^ e);

		/// <summary>
		/// 期货发起冲正银行转期货请求，银行处理完毕后报盘发回的通知的委托
		/// </summary>
		public delegate void DOnRtnRepealFromBankToFutureByFuture(TraderSpi^ sender, RtnRepealFromBankToFutureByFutureArgs^ e);

		/// <summary>
		/// 期货发起冲正期货转银行请求，银行处理完毕后报盘发回的通知的委托
		/// </summary>
		public delegate void DOnRtnRepealFromFutureToBankByFuture(TraderSpi^ sender, RtnRepealFromFutureToBankByFutureArgs^ e);

		/// <summary>
		/// 期货发起银行资金转期货应答的委托
		/// </summary>
		public delegate void DOnRspFromBankToFutureByFuture(TraderSpi^ sender, RspFromBankToFutureByFutureArgs^ e);

		/// <summary>
		/// 期货发起期货资金转银行应答的委托
		/// </summary>
		public delegate void DOnRspFromFutureToBankByFuture(TraderSpi^ sender, RspFromFutureToBankByFutureArgs^ e);

		/// <summary>
		/// 期货发起查询银行余额应答的委托
		/// </summary>
		public delegate void DOnRspQueryBankAccountMoneyByFuture(TraderSpi^ sender, RspQueryBankAccountMoneyByFutureArgs^ e);

		/// <summary>
		/// 银行发起银期开户通知的委托
		/// </summary>
		public delegate void DOnRtnOpenAccountByBank(TraderSpi^ sender, RtnOpenAccountByBankArgs^ e);

		/// <summary>
		/// 银行发起银期销户通知的委托
		/// </summary>
		public delegate void DOnRtnCancelAccountByBank(TraderSpi^ sender, RtnCancelAccountByBankArgs^ e);

		/// <summary>
		/// 银行发起变更银行账号通知的委托
		/// </summary>
		public delegate void DOnRtnChangeAccountByBank(TraderSpi^ sender, RtnChangeAccountByBankArgs^ e);

		/// <summary>
		/// 请求查询分类合约响应的委托
		/// </summary>
		public delegate void DOnRspQryClassifiedInstrument(TraderSpi^ sender, RspQryClassifiedInstrumentArgs^ e);

		/// <summary>
		/// 请求组合优惠比例响应的委托
		/// </summary>
		public delegate void DOnRspQryCombPromotionParam(TraderSpi^ sender, RspQryCombPromotionParamArgs^ e);

		/// <summary>
		/// 投资者风险结算持仓查询响应的委托
		/// </summary>
		public delegate void DOnRspQryRiskSettleInvstPosition(TraderSpi^ sender, RspQryRiskSettleInvstPositionArgs^ e);

		/// <summary>
		/// 风险结算产品查询响应的委托
		/// </summary>
		public delegate void DOnRspQryRiskSettleProductStatus(TraderSpi^ sender, RspQryRiskSettleProductStatusArgs^ e);
	}

}
