#pragma once
#include "pch.h"
#include "TraderSpi.h"

namespace PhoenixCTP
{
	class CTraderSpi :public CThostFtdcTraderSpi
	{
	public:
		System::IntPtr pTraderSpi;

		CTraderSpi(System::IntPtr intPTraderSpi);

		inline void setNetSpi(System::IntPtr intPTraderSpi);

		/// <summary>
		/// 当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
		/// </summary>
		inline virtual void OnFrontConnected() override;

		/// <summary>
		/// 0x2003 收到错误报文
		/// </summary>
		/// <param name="nReason"></param>
		inline virtual void OnFrontDisconnected(int nReason) override;

		/// <summary>
		/// @param nTimeLapse 距离上次接收报文的时间
		/// </summary>
		/// <param name="nTimeLapse"></param>
		inline virtual void OnHeartBeatWarning(int nTimeLapse) override;

		/// <summary>
		/// 客户端认证响应
		/// </summary>
		/// <param name="pRspAuthenticateField">客户端认证响应</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspAuthenticate(CThostFtdcRspAuthenticateField* pRspAuthenticateField, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 登录请求响应
		/// </summary>
		/// <param name="pRspUserLogin">用户登录应答</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspUserLogin(CThostFtdcRspUserLoginField* pRspUserLogin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 登出请求响应
		/// </summary>
		/// <param name="pUserLogout">用户登出请求</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspUserLogout(CThostFtdcUserLogoutField* pUserLogout, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 用户口令更新请求响应
		/// </summary>
		/// <param name="pUserPasswordUpdate">用户口令变更</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField* pUserPasswordUpdate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 资金账户口令更新请求响应
		/// </summary>
		/// <param name="pTradingAccountPasswordUpdate">资金账户口令变更域</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField* pTradingAccountPasswordUpdate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 查询用户当前支持的认证模式的回复
		/// </summary>
		/// <param name="pRspUserAuthMethod">用户发出获取安全安全登陆方法回复</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspUserAuthMethod(CThostFtdcRspUserAuthMethodField* pRspUserAuthMethod, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 获取图形验证码请求的回复
		/// </summary>
		/// <param name="pRspGenUserCaptcha">生成的图片验证码信息</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspGenUserCaptcha(CThostFtdcRspGenUserCaptchaField* pRspGenUserCaptcha, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 获取短信验证码请求的回复
		/// </summary>
		/// <param name="pRspGenUserText">短信验证码生成的回复</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspGenUserText(CThostFtdcRspGenUserTextField* pRspGenUserText, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 报单录入请求响应
		/// </summary>
		/// <param name="pInputOrder">输入报单</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspOrderInsert(CThostFtdcInputOrderField* pInputOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 预埋单录入请求响应
		/// </summary>
		/// <param name="pParkedOrder">预埋单</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspParkedOrderInsert(CThostFtdcParkedOrderField* pParkedOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 预埋撤单录入请求响应
		/// </summary>
		/// <param name="pParkedOrderAction">输入预埋单操作</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspParkedOrderAction(CThostFtdcParkedOrderActionField* pParkedOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 报单操作请求响应
		/// </summary>
		/// <param name="pInputOrderAction">输入报单操作</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspOrderAction(CThostFtdcInputOrderActionField* pInputOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 查询最大报单数量响应
		/// </summary>
		/// <param name="pQryMaxOrderVolume">查询最大报单数量</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryMaxOrderVolume(CThostFtdcQryMaxOrderVolumeField* pQryMaxOrderVolume, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 投资者结算结果确认响应
		/// </summary>
		/// <param name="pSettlementInfoConfirm">投资者结算结果确认信息</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField* pSettlementInfoConfirm, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 删除预埋单响应
		/// </summary>
		/// <param name="pRemoveParkedOrder">删除预埋单</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderField* pRemoveParkedOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 删除预埋撤单响应
		/// </summary>
		/// <param name="pRemoveParkedOrderAction">删除预埋撤单</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField* pRemoveParkedOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 执行宣告录入请求响应
		/// </summary>
		/// <param name="pInputExecOrder">输入的执行宣告</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspExecOrderInsert(CThostFtdcInputExecOrderField* pInputExecOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 执行宣告操作请求响应
		/// </summary>
		/// <param name="pInputExecOrderAction">输入执行宣告操作</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspExecOrderAction(CThostFtdcInputExecOrderActionField* pInputExecOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 询价录入请求响应
		/// </summary>
		/// <param name="pInputForQuote">输入的询价</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspForQuoteInsert(CThostFtdcInputForQuoteField* pInputForQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 报价录入请求响应
		/// </summary>
		/// <param name="pInputQuote">输入的报价</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQuoteInsert(CThostFtdcInputQuoteField* pInputQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 报价操作请求响应
		/// </summary>
		/// <param name="pInputQuoteAction">输入报价操作</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQuoteAction(CThostFtdcInputQuoteActionField* pInputQuoteAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 批量报单操作请求响应
		/// </summary>
		/// <param name="pInputBatchOrderAction">输入批量报单操作</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspBatchOrderAction(CThostFtdcInputBatchOrderActionField* pInputBatchOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 期权自对冲录入请求响应
		/// </summary>
		/// <param name="pInputOptionSelfClose">输入的期权自对冲</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField* pInputOptionSelfClose, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 期权自对冲操作请求响应
		/// </summary>
		/// <param name="pInputOptionSelfCloseAction">输入期权自对冲操作</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspOptionSelfCloseAction(CThostFtdcInputOptionSelfCloseActionField* pInputOptionSelfCloseAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 申请组合录入请求响应
		/// </summary>
		/// <param name="pInputCombAction">输入的申请组合</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspCombActionInsert(CThostFtdcInputCombActionField* pInputCombAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 请求查询报单响应
		/// </summary>
		/// <param name="pOrder">报单</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryOrder(CThostFtdcOrderField* pOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 请求查询成交响应
		/// </summary>
		/// <param name="pTrade">成交</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryTrade(CThostFtdcTradeField* pTrade, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 请求查询投资者持仓响应
		/// </summary>
		/// <param name="pInvestorPosition">投资者持仓</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryInvestorPosition(CThostFtdcInvestorPositionField* pInvestorPosition, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 请求查询资金账户响应
		/// </summary>
		/// <param name="pTradingAccount">资金账户</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryTradingAccount(CThostFtdcTradingAccountField* pTradingAccount, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 请求查询投资者响应
		/// </summary>
		/// <param name="pInvestor">投资者</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryInvestor(CThostFtdcInvestorField* pInvestor, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 请求查询交易编码响应
		/// </summary>
		/// <param name="pTradingCode">交易编码</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryTradingCode(CThostFtdcTradingCodeField* pTradingCode, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 请求查询合约保证金率响应
		/// </summary>
		/// <param name="pInstrumentMarginRate">合约保证金率</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField* pInstrumentMarginRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 请求查询合约手续费率响应
		/// </summary>
		/// <param name="pInstrumentCommissionRate">合约手续费率</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField* pInstrumentCommissionRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 请求查询交易所响应
		/// </summary>
		/// <param name="pExchange">交易所</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryExchange(CThostFtdcExchangeField* pExchange, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 请求查询产品响应
		/// </summary>
		/// <param name="pProduct">产品</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryProduct(CThostFtdcProductField* pProduct, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 请求查询合约响应
		/// </summary>
		/// <param name="pInstrument">合约</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryInstrument(CThostFtdcInstrumentField* pInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 请求查询行情响应
		/// </summary>
		/// <param name="pDepthMarketData">深度行情</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField* pDepthMarketData, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 请求查询投资者结算结果响应
		/// </summary>
		/// <param name="pSettlementInfo">投资者结算结果</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQrySettlementInfo(CThostFtdcSettlementInfoField* pSettlementInfo, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 请求查询转帐银行响应
		/// </summary>
		/// <param name="pTransferBank">转帐银行</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryTransferBank(CThostFtdcTransferBankField* pTransferBank, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 请求查询投资者持仓明细响应
		/// </summary>
		/// <param name="pInvestorPositionDetail">投资者持仓明细</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField* pInvestorPositionDetail, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 请求查询客户通知响应
		/// </summary>
		/// <param name="pNotice">客户通知</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryNotice(CThostFtdcNoticeField* pNotice, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 请求查询结算信息确认响应
		/// </summary>
		/// <param name="pSettlementInfoConfirm">投资者结算结果确认信息</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField* pSettlementInfoConfirm, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 请求查询投资者持仓明细响应
		/// </summary>
		/// <param name="pInvestorPositionCombineDetail">投资者组合持仓明细</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField* pInvestorPositionCombineDetail, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 查询保证金监管系统经纪公司资金账户密钥响应
		/// </summary>
		/// <param name="pCFMMCTradingAccountKey">保证金监管系统经纪公司资金账户密钥</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyField* pCFMMCTradingAccountKey, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 请求查询仓单折抵信息响应
		/// </summary>
		/// <param name="pEWarrantOffset">仓单折抵信息</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryEWarrantOffset(CThostFtdcEWarrantOffsetField* pEWarrantOffset, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 请求查询投资者品种跨品种保证金响应
		/// </summary>
		/// <param name="pInvestorProductGroupMargin">投资者品种跨品种保证金</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryInvestorProductGroupMargin(CThostFtdcInvestorProductGroupMarginField* pInvestorProductGroupMargin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 请求查询交易所保证金率响应
		/// </summary>
		/// <param name="pExchangeMarginRate">交易所保证金率</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryExchangeMarginRate(CThostFtdcExchangeMarginRateField* pExchangeMarginRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 请求查询交易所调整保证金率响应
		/// </summary>
		/// <param name="pExchangeMarginRateAdjust">交易所保证金率调整</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryExchangeMarginRateAdjust(CThostFtdcExchangeMarginRateAdjustField* pExchangeMarginRateAdjust, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 请求查询汇率响应
		/// </summary>
		/// <param name="pExchangeRate">汇率</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryExchangeRate(CThostFtdcExchangeRateField* pExchangeRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 请求查询二级代理操作员银期权限响应
		/// </summary>
		/// <param name="pSecAgentACIDMap">二级代理操作员银期权限</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQrySecAgentACIDMap(CThostFtdcSecAgentACIDMapField* pSecAgentACIDMap, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 请求查询产品报价汇率
		/// </summary>
		/// <param name="pProductExchRate">产品报价汇率</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryProductExchRate(CThostFtdcProductExchRateField* pProductExchRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 请求查询产品组
		/// </summary>
		/// <param name="pProductGroup">投资者品种跨品种保证金产品组</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryProductGroup(CThostFtdcProductGroupField* pProductGroup, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 请求查询做市商合约手续费率响应
		/// </summary>
		/// <param name="pMMInstrumentCommissionRate">做市商合约手续费率</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryMMInstrumentCommissionRate(CThostFtdcMMInstrumentCommissionRateField* pMMInstrumentCommissionRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 请求查询做市商期权合约手续费响应
		/// </summary>
		/// <param name="pMMOptionInstrCommRate">当前做市商期权合约手续费的详细内容</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryMMOptionInstrCommRate(CThostFtdcMMOptionInstrCommRateField* pMMOptionInstrCommRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 请求查询报单手续费响应
		/// </summary>
		/// <param name="pInstrumentOrderCommRate">当前报单手续费的详细内容</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryInstrumentOrderCommRate(CThostFtdcInstrumentOrderCommRateField* pInstrumentOrderCommRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 请求查询资金账户响应
		/// </summary>
		/// <param name="pTradingAccount">资金账户</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQrySecAgentTradingAccount(CThostFtdcTradingAccountField* pTradingAccount, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 请求查询二级代理商资金校验模式响应
		/// </summary>
		/// <param name="pSecAgentCheckMode">二级代理商资金校验模式</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQrySecAgentCheckMode(CThostFtdcSecAgentCheckModeField* pSecAgentCheckMode, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 请求查询二级代理商信息响应
		/// </summary>
		/// <param name="pSecAgentTradeInfo">二级代理商信息</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQrySecAgentTradeInfo(CThostFtdcSecAgentTradeInfoField* pSecAgentTradeInfo, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 请求查询期权交易成本响应
		/// </summary>
		/// <param name="pOptionInstrTradeCost">期权交易成本</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryOptionInstrTradeCost(CThostFtdcOptionInstrTradeCostField* pOptionInstrTradeCost, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 请求查询期权合约手续费响应
		/// </summary>
		/// <param name="pOptionInstrCommRate">当前期权合约手续费的详细内容</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryOptionInstrCommRate(CThostFtdcOptionInstrCommRateField* pOptionInstrCommRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 请求查询执行宣告响应
		/// </summary>
		/// <param name="pExecOrder">执行宣告</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryExecOrder(CThostFtdcExecOrderField* pExecOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 请求查询询价响应
		/// </summary>
		/// <param name="pForQuote">询价</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryForQuote(CThostFtdcForQuoteField* pForQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 请求查询报价响应
		/// </summary>
		/// <param name="pQuote">报价</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryQuote(CThostFtdcQuoteField* pQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 请求查询期权自对冲响应
		/// </summary>
		/// <param name="pOptionSelfClose">期权自对冲</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryOptionSelfClose(CThostFtdcOptionSelfCloseField* pOptionSelfClose, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 请求查询投资单元响应
		/// </summary>
		/// <param name="pInvestUnit">投资单元</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryInvestUnit(CThostFtdcInvestUnitField* pInvestUnit, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 请求查询组合合约安全系数响应
		/// </summary>
		/// <param name="pCombInstrumentGuard">组合合约安全系数</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryCombInstrumentGuard(CThostFtdcCombInstrumentGuardField* pCombInstrumentGuard, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 请求查询申请组合响应
		/// </summary>
		/// <param name="pCombAction">申请组合</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryCombAction(CThostFtdcCombActionField* pCombAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 请求查询转帐流水响应
		/// </summary>
		/// <param name="pTransferSerial">银期转账交易流水表</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryTransferSerial(CThostFtdcTransferSerialField* pTransferSerial, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 请求查询银期签约关系响应
		/// </summary>
		/// <param name="pAccountregister">客户开销户信息表</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryAccountregister(CThostFtdcAccountregisterField* pAccountregister, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 错误应答
		/// </summary>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspError(CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 报单通知
		/// </summary>
		/// <param name="pOrder">报单</param>
		inline virtual void OnRtnOrder(CThostFtdcOrderField* pOrder) override;

		/// <summary>
		/// 成交通知
		/// </summary>
		/// <param name="pTrade">成交</param>
		inline virtual void OnRtnTrade(CThostFtdcTradeField* pTrade) override;

		/// <summary>
		/// 报单录入错误回报
		/// </summary>
		/// <param name="pInputOrder">输入报单</param>
		/// <param name="pRspInfo">响应信息</param>
		inline virtual void OnErrRtnOrderInsert(CThostFtdcInputOrderField* pInputOrder, CThostFtdcRspInfoField* pRspInfo) override;

		/// <summary>
		/// 报单操作错误回报
		/// </summary>
		/// <param name="pOrderAction">报单操作</param>
		/// <param name="pRspInfo">响应信息</param>
		inline virtual void OnErrRtnOrderAction(CThostFtdcOrderActionField* pOrderAction, CThostFtdcRspInfoField* pRspInfo) override;

		/// <summary>
		/// 合约交易状态通知
		/// </summary>
		/// <param name="pInstrumentStatus">合约状态</param>
		inline virtual void OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField* pInstrumentStatus) override;

		/// <summary>
		/// 交易所公告通知
		/// </summary>
		/// <param name="pBulletin">交易所公告</param>
		inline virtual void OnRtnBulletin(CThostFtdcBulletinField* pBulletin) override;

		/// <summary>
		/// 交易通知
		/// </summary>
		/// <param name="pTradingNoticeInfo">用户事件通知信息</param>
		inline virtual void OnRtnTradingNotice(CThostFtdcTradingNoticeInfoField* pTradingNoticeInfo) override;

		/// <summary>
		/// 提示条件单校验错误
		/// </summary>
		/// <param name="pErrorConditionalOrder">查询错误报单操作</param>
		inline virtual void OnRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderField* pErrorConditionalOrder) override;

		/// <summary>
		/// 执行宣告通知
		/// </summary>
		/// <param name="pExecOrder">执行宣告</param>
		inline virtual void OnRtnExecOrder(CThostFtdcExecOrderField* pExecOrder) override;

		/// <summary>
		/// 执行宣告录入错误回报
		/// </summary>
		/// <param name="pInputExecOrder">输入的执行宣告</param>
		/// <param name="pRspInfo">响应信息</param>
		inline virtual void OnErrRtnExecOrderInsert(CThostFtdcInputExecOrderField* pInputExecOrder, CThostFtdcRspInfoField* pRspInfo) override;

		/// <summary>
		/// 执行宣告操作错误回报
		/// </summary>
		/// <param name="pExecOrderAction">执行宣告操作</param>
		/// <param name="pRspInfo">响应信息</param>
		inline virtual void OnErrRtnExecOrderAction(CThostFtdcExecOrderActionField* pExecOrderAction, CThostFtdcRspInfoField* pRspInfo) override;

		/// <summary>
		/// 询价录入错误回报
		/// </summary>
		/// <param name="pInputForQuote">输入的询价</param>
		/// <param name="pRspInfo">响应信息</param>
		inline virtual void OnErrRtnForQuoteInsert(CThostFtdcInputForQuoteField* pInputForQuote, CThostFtdcRspInfoField* pRspInfo) override;

		/// <summary>
		/// 报价通知
		/// </summary>
		/// <param name="pQuote">报价</param>
		inline virtual void OnRtnQuote(CThostFtdcQuoteField* pQuote) override;

		/// <summary>
		/// 报价录入错误回报
		/// </summary>
		/// <param name="pInputQuote">输入的报价</param>
		/// <param name="pRspInfo">响应信息</param>
		inline virtual void OnErrRtnQuoteInsert(CThostFtdcInputQuoteField* pInputQuote, CThostFtdcRspInfoField* pRspInfo) override;

		/// <summary>
		/// 报价操作错误回报
		/// </summary>
		/// <param name="pQuoteAction">报价操作</param>
		/// <param name="pRspInfo">响应信息</param>
		inline virtual void OnErrRtnQuoteAction(CThostFtdcQuoteActionField* pQuoteAction, CThostFtdcRspInfoField* pRspInfo) override;

		/// <summary>
		/// 询价通知
		/// </summary>
		/// <param name="pForQuoteRsp">发给做市商的询价请求</param>
		inline virtual void OnRtnForQuoteRsp(CThostFtdcForQuoteRspField* pForQuoteRsp) override;

		/// <summary>
		/// 保证金监控中心用户令牌
		/// </summary>
		/// <param name="pCFMMCTradingAccountToken">监控中心用户令牌</param>
		inline virtual void OnRtnCFMMCTradingAccountToken(CThostFtdcCFMMCTradingAccountTokenField* pCFMMCTradingAccountToken) override;

		/// <summary>
		/// 批量报单操作错误回报
		/// </summary>
		/// <param name="pBatchOrderAction">批量报单操作</param>
		/// <param name="pRspInfo">响应信息</param>
		inline virtual void OnErrRtnBatchOrderAction(CThostFtdcBatchOrderActionField* pBatchOrderAction, CThostFtdcRspInfoField* pRspInfo) override;

		/// <summary>
		/// 期权自对冲通知
		/// </summary>
		/// <param name="pOptionSelfClose">期权自对冲</param>
		inline virtual void OnRtnOptionSelfClose(CThostFtdcOptionSelfCloseField* pOptionSelfClose) override;

		/// <summary>
		/// 期权自对冲录入错误回报
		/// </summary>
		/// <param name="pInputOptionSelfClose">输入的期权自对冲</param>
		/// <param name="pRspInfo">响应信息</param>
		inline virtual void OnErrRtnOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField* pInputOptionSelfClose, CThostFtdcRspInfoField* pRspInfo) override;

		/// <summary>
		/// 期权自对冲操作错误回报
		/// </summary>
		/// <param name="pOptionSelfCloseAction">期权自对冲操作</param>
		/// <param name="pRspInfo">响应信息</param>
		inline virtual void OnErrRtnOptionSelfCloseAction(CThostFtdcOptionSelfCloseActionField* pOptionSelfCloseAction, CThostFtdcRspInfoField* pRspInfo) override;

		/// <summary>
		/// 申请组合通知
		/// </summary>
		/// <param name="pCombAction">申请组合</param>
		inline virtual void OnRtnCombAction(CThostFtdcCombActionField* pCombAction) override;

		/// <summary>
		/// 申请组合录入错误回报
		/// </summary>
		/// <param name="pInputCombAction">输入的申请组合</param>
		/// <param name="pRspInfo">响应信息</param>
		inline virtual void OnErrRtnCombActionInsert(CThostFtdcInputCombActionField* pInputCombAction, CThostFtdcRspInfoField* pRspInfo) override;

		/// <summary>
		/// 请求查询签约银行响应
		/// </summary>
		/// <param name="pContractBank">查询签约银行响应</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryContractBank(CThostFtdcContractBankField* pContractBank, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 请求查询预埋单响应
		/// </summary>
		/// <param name="pParkedOrder">预埋单</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryParkedOrder(CThostFtdcParkedOrderField* pParkedOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 请求查询预埋撤单响应
		/// </summary>
		/// <param name="pParkedOrderAction">输入预埋单操作</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryParkedOrderAction(CThostFtdcParkedOrderActionField* pParkedOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 请求查询交易通知响应
		/// </summary>
		/// <param name="pTradingNotice">用户事件通知</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryTradingNotice(CThostFtdcTradingNoticeField* pTradingNotice, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 请求查询经纪公司交易参数响应
		/// </summary>
		/// <param name="pBrokerTradingParams">经纪公司交易参数</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryBrokerTradingParams(CThostFtdcBrokerTradingParamsField* pBrokerTradingParams, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 请求查询经纪公司交易算法响应
		/// </summary>
		/// <param name="pBrokerTradingAlgos">经纪公司交易算法</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosField* pBrokerTradingAlgos, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 请求查询监控中心用户令牌
		/// </summary>
		/// <param name="pQueryCFMMCTradingAccountToken">查询监控中心用户令牌</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenField* pQueryCFMMCTradingAccountToken, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 银行发起银行资金转期货通知
		/// </summary>
		/// <param name="pRspTransfer">银行发起银行资金转期货响应</param>
		inline virtual void OnRtnFromBankToFutureByBank(CThostFtdcRspTransferField* pRspTransfer) override;

		/// <summary>
		/// 银行发起期货资金转银行通知
		/// </summary>
		/// <param name="pRspTransfer">银行发起银行资金转期货响应</param>
		inline virtual void OnRtnFromFutureToBankByBank(CThostFtdcRspTransferField* pRspTransfer) override;

		/// <summary>
		/// 银行发起冲正银行转期货通知
		/// </summary>
		/// <param name="pRspRepeal">冲正响应</param>
		inline virtual void OnRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealField* pRspRepeal) override;

		/// <summary>
		/// 银行发起冲正期货转银行通知
		/// </summary>
		/// <param name="pRspRepeal">冲正响应</param>
		inline virtual void OnRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealField* pRspRepeal) override;

		/// <summary>
		/// 期货发起银行资金转期货通知
		/// </summary>
		/// <param name="pRspTransfer">银行发起银行资金转期货响应</param>
		inline virtual void OnRtnFromBankToFutureByFuture(CThostFtdcRspTransferField* pRspTransfer) override;

		/// <summary>
		/// 期货发起期货资金转银行通知
		/// </summary>
		/// <param name="pRspTransfer">银行发起银行资金转期货响应</param>
		inline virtual void OnRtnFromFutureToBankByFuture(CThostFtdcRspTransferField* pRspTransfer) override;

		/// <summary>
		/// 系统运行时期货端手工发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
		/// </summary>
		/// <param name="pRspRepeal">冲正响应</param>
		inline virtual void OnRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealField* pRspRepeal) override;

		/// <summary>
		/// 系统运行时期货端手工发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
		/// </summary>
		/// <param name="pRspRepeal">冲正响应</param>
		inline virtual void OnRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealField* pRspRepeal) override;

		/// <summary>
		/// 期货发起查询银行余额通知
		/// </summary>
		/// <param name="pNotifyQueryAccount">查询账户信息通知</param>
		inline virtual void OnRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField* pNotifyQueryAccount) override;

		/// <summary>
		/// 期货发起银行资金转期货错误回报
		/// </summary>
		/// <param name="pReqTransfer">转账请求</param>
		/// <param name="pRspInfo">响应信息</param>
		inline virtual void OnErrRtnBankToFutureByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo) override;

		/// <summary>
		/// 期货发起期货资金转银行错误回报
		/// </summary>
		/// <param name="pReqTransfer">转账请求</param>
		/// <param name="pRspInfo">响应信息</param>
		inline virtual void OnErrRtnFutureToBankByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo) override;

		/// <summary>
		/// 系统运行时期货端手工发起冲正银行转期货错误回报
		/// </summary>
		/// <param name="pReqRepeal">冲正请求</param>
		/// <param name="pRspInfo">响应信息</param>
		inline virtual void OnErrRtnRepealBankToFutureByFutureManual(CThostFtdcReqRepealField* pReqRepeal, CThostFtdcRspInfoField* pRspInfo) override;

		/// <summary>
		/// 系统运行时期货端手工发起冲正期货转银行错误回报
		/// </summary>
		/// <param name="pReqRepeal">冲正请求</param>
		/// <param name="pRspInfo">响应信息</param>
		inline virtual void OnErrRtnRepealFutureToBankByFutureManual(CThostFtdcReqRepealField* pReqRepeal, CThostFtdcRspInfoField* pRspInfo) override;

		/// <summary>
		/// 期货发起查询银行余额错误回报
		/// </summary>
		/// <param name="pReqQueryAccount">查询账户信息请求</param>
		/// <param name="pRspInfo">响应信息</param>
		inline virtual void OnErrRtnQueryBankBalanceByFuture(CThostFtdcReqQueryAccountField* pReqQueryAccount, CThostFtdcRspInfoField* pRspInfo) override;

		/// <summary>
		/// 期货发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
		/// </summary>
		/// <param name="pRspRepeal">冲正响应</param>
		inline virtual void OnRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealField* pRspRepeal) override;

		/// <summary>
		/// 期货发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
		/// </summary>
		/// <param name="pRspRepeal">冲正响应</param>
		inline virtual void OnRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealField* pRspRepeal) override;

		/// <summary>
		/// 期货发起银行资金转期货应答
		/// </summary>
		/// <param name="pReqTransfer">转账请求</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspFromBankToFutureByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 期货发起期货资金转银行应答
		/// </summary>
		/// <param name="pReqTransfer">转账请求</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspFromFutureToBankByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 期货发起查询银行余额应答
		/// </summary>
		/// <param name="pReqQueryAccount">查询账户信息请求</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField* pReqQueryAccount, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 银行发起银期开户通知
		/// </summary>
		/// <param name="pOpenAccount">银期开户信息</param>
		inline virtual void OnRtnOpenAccountByBank(CThostFtdcOpenAccountField* pOpenAccount) override;

		/// <summary>
		/// 银行发起银期销户通知
		/// </summary>
		/// <param name="pCancelAccount">银期销户信息</param>
		inline virtual void OnRtnCancelAccountByBank(CThostFtdcCancelAccountField* pCancelAccount) override;

		/// <summary>
		/// 银行发起变更银行账号通知
		/// </summary>
		/// <param name="pChangeAccount">银期变更银行账号信息</param>
		inline virtual void OnRtnChangeAccountByBank(CThostFtdcChangeAccountField* pChangeAccount) override;

		/// <summary>
		/// 请求查询分类合约响应
		/// </summary>
		/// <param name="pInstrument">合约</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryClassifiedInstrument(CThostFtdcInstrumentField* pInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 请求组合优惠比例响应
		/// </summary>
		/// <param name="pCombPromotionParam">组合优惠比例</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryCombPromotionParam(CThostFtdcCombPromotionParamField* pCombPromotionParam, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 投资者风险结算持仓查询响应
		/// </summary>
		/// <param name="pRiskSettleInvstPosition">投资者风险结算持仓</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryRiskSettleInvstPosition(CThostFtdcRiskSettleInvstPositionField* pRiskSettleInvstPosition, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		/// <summary>
		/// 风险结算产品查询响应
		/// </summary>
		/// <param name="pRiskSettleProductStatus">风险品种</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryRiskSettleProductStatus(CThostFtdcRiskSettleProductStatusField* pRiskSettleProductStatus, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;
	};
}
