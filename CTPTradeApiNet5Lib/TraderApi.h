#pragma once
#include "pch.h"
#include "ApiStructs.h"
#include "TraderSpi.h"

namespace PhoenixCTP
{
	public ref class TraderApi
	{
	public:

		/// <summary>
		/// 用于储存非托管的CThostFtdcTraderApi结构体指针的变量
		/// </summary>
		CThostFtdcTraderApi* CApi = nullptr;

		/// <summary>
		/// 用于储存绑定的TraderSpi托管结构的成员变量
		/// </summary>
		TraderSpi^ Spi = nullptr;

		/// <summary>
		/// 将成员变量Spi设置成为参数的TraderSpi
		/// </summary>
		/// <param name="pSpi">托管TraderSpi结构体</param>
		inline void SetSpi(TraderSpi^ pSpi);
		
		/// <summary>
		/// 创建TraderApi
		/// </summary>
		/// <param name="pszFlowPath">储存订阅信息的文件目录，默认为当前目录</param>
		/// <returns>创建出的UserApi指针</returns>
		inline static CThostFtdcTraderApi* CreateFtdcTraderApi(System::String^ pszFlowPath);

		/// <summary>
		/// 获取API的版本信息
		/// </summary>
		/// <returns>获取到的版本号</returns>
		inline static System::String^ GetApiVersion();

		/// <summary>
		/// 删除对象接口本身
		/// </summary>
		/// <remarks>不再使用本接口对象时,调用该函数删除接口对象</remarks>
		inline virtual void Release();

		/// <summary>
		/// 初始化
		/// </summary>
		/// <remarks>初始化运行环境,只有调用后,接口才开始工作</remarks>
		inline virtual void Init();

		/// <summary>
		/// 等待线程接口结束运行
		/// </summary>
		/// <returns>线程退出代码</returns>
		inline virtual int Join();

		/// <summary>
		/// 获取当前交易日
		/// </summary>
		/// <returns>获取到的交易日</returns>
		/// <remarks>只有登陆成功后，才能得到正确的交易日</remarks>
		inline virtual System::String^ GetTradingDay();

		/// <summary>
		/// 注册前置机网络地址
		/// </summary>
		/// <param name="pszFrontAddress">前置机网络地址。</param>
		/// <remarks>网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:17001”。</remarks>
		/// <remarks>“tcp”代表传输协议，“127.0.0.1”代表服务器地址。”17001”代表服务器端口号。</remarks>
		inline virtual void RegisterFront(System::String^ pszFrontAddress);

		/// <summary>
		/// 注册名字服务器网络地址
		/// </summary>
		/// <param name="pszNsAddress">名字服务器网络地址。</param>
		/// <remarks>网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:12001”。</remarks>
		/// <remarks>“tcp”代表传输协议，“127.0.0.1”代表服务器地址。”12001”代表服务器端口号。</remarks>
		/// <remarks>RegisterNameServer优先于RegisterFront</remarks>
		inline virtual void RegisterNameServer(System::String^ pszNsAddress);

		/// <summary>
		/// 注册名字服务器用户信息
		/// </summary>
		/// <param name="pFensUserInfo">用户信息</param>
		inline virtual void RegisterFensUserInfo(FensUserInfoField^ pFensUserInfo);

		/// <summary>
		/// 注册回调接口
		/// </summary>
		/// <param name="pSpi">派生自回调接口类的实例</param>
		inline virtual void RegisterSpi(TraderSpi^ pSpi);

		/// <summary>
		/// 订阅私有流。
		/// </summary>
		/// <param name="nResumeType">私有流重传方式  
		/// THOST_TERT_RESTART:从本交易日开始重传
		/// THOST_TERT_RESUME:从上次收到的续传
		/// THOST_TERT_QUICK:只传送登录后私有流的内容</param>
		/// <remarks>该方法要在Init方法前调用。若不调用则不会收到私有流的数据。</remarks>
		inline virtual void SubscribePrivateTopic(THOST_TE_RESUME_TYPE nResumeType);

		/// <summary>
		/// 订阅公共流
		/// </summary>
		/// <param name="nResumeType">公共流重传方式
		/// THOST_TERT_RESTART:从本交易日开始重传
		/// THOST_TERT_RESUME:从上次收到的续传
		/// THOST_TERT_QUICK:只传送登录后私有流的内容</param>
		/// /// <remarks>该方法要在Init方法前调用。若不调用则不会收到公共流的数据。</remarks>
		inline virtual void SubscribePublicTopic(THOST_TE_RESUME_TYPE nResumeType);		

		/// <summary>
		/// 客户端认证请求
		/// </summary>
		/// <param name="pReqAuthenticateField">客户端认证请求</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqAuthenticate(ReqAuthenticateField^ pReqAuthenticateField, int nRequestID);

		/// <summary>
		/// 注册用户终端信息，用于中继服务器多连接模式
		/// 需要在终端认证成功后，用户登录前调用该接口
		/// </summary>
		/// <param name="pUserSystemInfo">用户系统信息</param>
		inline virtual int RegisterUserSystemInfo(UserSystemInfoField^ pUserSystemInfo);

		/// <summary>
		/// 上报用户终端信息，用于中继服务器操作员登陆模式
		/// 操作员登录后，可以多次调用该接口上报客户信息
		/// </summary>
		/// <param name="pUserSystemInfo">用户系统信息</param>
		inline virtual int SubmitUserSystemInfo(UserSystemInfoField^ pUserSystemInfo);

		/// <summary>
		/// 用户登录请求
		/// </summary>
		/// <param name="pReqUserLoginField">用户登录请求</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqUserLogin(ReqUserLoginField^ pReqUserLoginField, int nRequestID);

		/// <summary>
		/// 登出请求
		/// </summary>
		/// <param name="pUserLogout">用户登出请求</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqUserLogout(UserLogoutField^ pUserLogout, int nRequestID);

		/// <summary>
		/// 用户口令更新请求
		/// </summary>
		/// <param name="pUserPasswordUpdate">用户口令变更</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqUserPasswordUpdate(UserPasswordUpdateField^ pUserPasswordUpdate, int nRequestID);

		/// <summary>
		/// 资金账户口令更新请求
		/// </summary>
		/// <param name="pTradingAccountPasswordUpdate">资金账户口令变更域</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqTradingAccountPasswordUpdate(TradingAccountPasswordUpdateField^ pTradingAccountPasswordUpdate, int nRequestID);

		/// <summary>
		/// 查询用户当前支持的认证模式
		/// </summary>
		/// <param name="pReqUserAuthMethod">用户发出获取安全安全登陆方法请求</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqUserAuthMethod(ReqUserAuthMethodField^ pReqUserAuthMethod, int nRequestID);

		/// <summary>
		/// 用户发出获取图形验证码请求
		/// </summary>
		/// <param name="pReqGenUserCaptcha">用户发出获取安全安全登陆方法请求</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqGenUserCaptcha(ReqGenUserCaptchaField^ pReqGenUserCaptcha, int nRequestID);

		/// <summary>
		/// 用户发出获取短信验证码请求
		/// </summary>
		/// <param name="pReqGenUserText">用户发出获取安全安全登陆方法请求</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqGenUserText(ReqGenUserTextField^ pReqGenUserText, int nRequestID);

		/// <summary>
		/// 用户发出带有图片验证码的登陆请求
		/// </summary>
		/// <param name="pReqUserLoginWithCaptcha">用户发出带图形验证码的登录请求请求</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqUserLoginWithCaptcha(ReqUserLoginWithCaptchaField^ pReqUserLoginWithCaptcha, int nRequestID);

		/// <summary>
		/// 用户发出带有短信验证码的登陆请求
		/// </summary>
		/// <param name="pReqUserLoginWithText">用户发出带短信验证码的登录请求请求</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqUserLoginWithText(ReqUserLoginWithTextField^ pReqUserLoginWithText, int nRequestID);

		/// <summary>
		/// 用户发出带有动态口令的登陆请求
		/// </summary>
		/// <param name="pReqUserLoginWithOTP">用户发出带动态验证码的登录请求请求</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqUserLoginWithOTP(ReqUserLoginWithOTPField^ pReqUserLoginWithOTP, int nRequestID);

		/// <summary>
		/// 报单录入请求
		/// </summary>
		/// <param name="pInputOrder">输入报单</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqOrderInsert(InputOrderField^ pInputOrder, int nRequestID);

		/// <summary>
		/// 预埋单录入请求
		/// </summary>
		/// <param name="pParkedOrder">预埋单</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqParkedOrderInsert(ParkedOrderField^ pParkedOrder, int nRequestID);

		/// <summary>
		/// 预埋撤单录入请求
		/// </summary>
		/// <param name="pParkedOrderAction">输入预埋单操作</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqParkedOrderAction(ParkedOrderActionField^ pParkedOrderAction, int nRequestID);

		/// <summary>
		/// 报单操作请求
		/// </summary>
		/// <param name="pInputOrderAction">输入报单操作</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqOrderAction(InputOrderActionField^ pInputOrderAction, int nRequestID);

		/// <summary>
		/// 查询最大报单数量请求
		/// </summary>
		/// <param name="pQryMaxOrderVolume">查询最大报单数量</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQryMaxOrderVolume(QryMaxOrderVolumeField^ pQryMaxOrderVolume, int nRequestID);

		/// <summary>
		/// 投资者结算结果确认
		/// </summary>
		/// <param name="pSettlementInfoConfirm">投资者结算结果确认信息</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqSettlementInfoConfirm(SettlementInfoConfirmField^ pSettlementInfoConfirm, int nRequestID);

		/// <summary>
		/// 请求删除预埋单
		/// </summary>
		/// <param name="pRemoveParkedOrder">删除预埋单</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqRemoveParkedOrder(RemoveParkedOrderField^ pRemoveParkedOrder, int nRequestID);

		/// <summary>
		/// 请求删除预埋撤单
		/// </summary>
		/// <param name="pRemoveParkedOrderAction">删除预埋撤单</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqRemoveParkedOrderAction(RemoveParkedOrderActionField^ pRemoveParkedOrderAction, int nRequestID);

		/// <summary>
		/// 执行宣告录入请求
		/// </summary>
		/// <param name="pInputExecOrder">输入的执行宣告</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqExecOrderInsert(InputExecOrderField^ pInputExecOrder, int nRequestID);

		/// <summary>
		/// 执行宣告操作请求
		/// </summary>
		/// <param name="pInputExecOrderAction">输入执行宣告操作</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqExecOrderAction(InputExecOrderActionField^ pInputExecOrderAction, int nRequestID);

		/// <summary>
		/// 询价录入请求
		/// </summary>
		/// <param name="pInputForQuote">输入的询价</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqForQuoteInsert(InputForQuoteField^ pInputForQuote, int nRequestID);

		/// <summary>
		/// 报价录入请求
		/// </summary>
		/// <param name="pInputQuote">输入的报价</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQuoteInsert(InputQuoteField^ pInputQuote, int nRequestID);

		/// <summary>
		/// 报价操作请求
		/// </summary>
		/// <param name="pInputQuoteAction">输入报价操作</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQuoteAction(InputQuoteActionField^ pInputQuoteAction, int nRequestID);

		/// <summary>
		/// 批量报单操作请求
		/// </summary>
		/// <param name="pInputBatchOrderAction">输入批量报单操作</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqBatchOrderAction(InputBatchOrderActionField^ pInputBatchOrderAction, int nRequestID);

		/// <summary>
		/// 期权自对冲录入请求
		/// </summary>
		/// <param name="pInputOptionSelfClose">输入的期权自对冲</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqOptionSelfCloseInsert(InputOptionSelfCloseField^ pInputOptionSelfClose, int nRequestID);

		/// <summary>
		/// 期权自对冲操作请求
		/// </summary>
		/// <param name="pInputOptionSelfCloseAction">输入期权自对冲操作</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqOptionSelfCloseAction(InputOptionSelfCloseActionField^ pInputOptionSelfCloseAction, int nRequestID);

		/// <summary>
		/// 申请组合录入请求
		/// </summary>
		/// <param name="pInputCombAction">输入的申请组合</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqCombActionInsert(InputCombActionField^ pInputCombAction, int nRequestID);

		/// <summary>
		/// 请求查询报单
		/// </summary>
		/// <param name="pQryOrder">查询报单</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQryOrder(QryOrderField^ pQryOrder, int nRequestID);

		/// <summary>
		/// 请求查询成交
		/// </summary>
		/// <param name="pQryTrade">查询成交</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQryTrade(QryTradeField^ pQryTrade, int nRequestID);

		/// <summary>
		/// 请求查询投资者持仓
		/// </summary>
		/// <param name="pQryInvestorPosition">查询投资者持仓</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQryInvestorPosition(QryInvestorPositionField^ pQryInvestorPosition, int nRequestID);

		/// <summary>
		/// 请求查询资金账户
		/// </summary>
		/// <param name="pQryTradingAccount">查询资金账户</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQryTradingAccount(QryTradingAccountField^ pQryTradingAccount, int nRequestID);

		/// <summary>
		/// 请求查询投资者
		/// </summary>
		/// <param name="pQryInvestor">查询投资者</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQryInvestor(QryInvestorField^ pQryInvestor, int nRequestID);

		/// <summary>
		/// 请求查询交易编码
		/// </summary>
		/// <param name="pQryTradingCode">查询交易编码</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQryTradingCode(QryTradingCodeField^ pQryTradingCode, int nRequestID);

		/// <summary>
		/// 请求查询合约保证金率
		/// </summary>
		/// <param name="pQryInstrumentMarginRate">查询合约保证金率</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQryInstrumentMarginRate(QryInstrumentMarginRateField^ pQryInstrumentMarginRate, int nRequestID);

		/// <summary>
		/// 请求查询合约手续费率
		/// </summary>
		/// <param name="pQryInstrumentCommissionRate">查询手续费率</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQryInstrumentCommissionRate(QryInstrumentCommissionRateField^ pQryInstrumentCommissionRate, int nRequestID);

		/// <summary>
		/// 请求查询交易所
		/// </summary>
		/// <param name="pQryExchange">查询交易所</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQryExchange(QryExchangeField^ pQryExchange, int nRequestID);

		/// <summary>
		/// 请求查询产品
		/// </summary>
		/// <param name="pQryProduct">查询产品</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQryProduct(QryProductField^ pQryProduct, int nRequestID);

		/// <summary>
		/// 请求查询合约
		/// </summary>
		/// <param name="pQryInstrument">查询合约</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQryInstrument(QryInstrumentField^ pQryInstrument, int nRequestID);

		/// <summary>
		/// 请求查询行情
		/// </summary>
		/// <param name="pQryDepthMarketData">查询行情</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQryDepthMarketData(QryDepthMarketDataField^ pQryDepthMarketData, int nRequestID);

		/// <summary>
		/// 请求查询投资者结算结果
		/// </summary>
		/// <param name="pQrySettlementInfo">查询投资者结算结果</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQrySettlementInfo(QrySettlementInfoField^ pQrySettlementInfo, int nRequestID);

		/// <summary>
		/// 请求查询转帐银行
		/// </summary>
		/// <param name="pQryTransferBank">查询转帐银行</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQryTransferBank(QryTransferBankField^ pQryTransferBank, int nRequestID);

		/// <summary>
		/// 请求查询投资者持仓明细
		/// </summary>
		/// <param name="pQryInvestorPositionDetail">查询投资者持仓明细</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQryInvestorPositionDetail(QryInvestorPositionDetailField^ pQryInvestorPositionDetail, int nRequestID);

		/// <summary>
		/// 请求查询客户通知
		/// </summary>
		/// <param name="pQryNotice">查询客户通知</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQryNotice(QryNoticeField^ pQryNotice, int nRequestID);

		/// <summary>
		/// 请求查询结算信息确认
		/// </summary>
		/// <param name="pQrySettlementInfoConfirm">查询结算信息确认域</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQrySettlementInfoConfirm(QrySettlementInfoConfirmField^ pQrySettlementInfoConfirm, int nRequestID);

		/// <summary>
		/// 请求查询投资者持仓明细
		/// </summary>
		/// <param name="pQryInvestorPositionCombineDetail">查询组合持仓明细</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQryInvestorPositionCombineDetail(QryInvestorPositionCombineDetailField^ pQryInvestorPositionCombineDetail, int nRequestID);

		/// <summary>
		/// 请求查询保证金监管系统经纪公司资金账户密钥
		/// </summary>
		/// <param name="pQryCFMMCTradingAccountKey">请求查询保证金监管系统经纪公司资金账户密钥</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQryCFMMCTradingAccountKey(QryCFMMCTradingAccountKeyField^ pQryCFMMCTradingAccountKey, int nRequestID);

		/// <summary>
		/// 请求查询仓单折抵信息
		/// </summary>
		/// <param name="pQryEWarrantOffset">查询仓单折抵信息</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQryEWarrantOffset(QryEWarrantOffsetField^ pQryEWarrantOffset, int nRequestID);

		/// <summary>
		/// 请求查询投资者品种跨品种保证金
		/// </summary>
		/// <param name="pQryInvestorProductGroupMargin">查询投资者品种跨品种保证金</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQryInvestorProductGroupMargin(QryInvestorProductGroupMarginField^ pQryInvestorProductGroupMargin, int nRequestID);

		/// <summary>
		/// 请求查询交易所保证金率
		/// </summary>
		/// <param name="pQryExchangeMarginRate">查询交易所保证金率</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQryExchangeMarginRate(QryExchangeMarginRateField^ pQryExchangeMarginRate, int nRequestID);

		/// <summary>
		/// 请求查询交易所调整保证金率
		/// </summary>
		/// <param name="pQryExchangeMarginRateAdjust">查询交易所调整保证金率</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQryExchangeMarginRateAdjust(QryExchangeMarginRateAdjustField^ pQryExchangeMarginRateAdjust, int nRequestID);

		/// <summary>
		/// 请求查询汇率
		/// </summary>
		/// <param name="pQryExchangeRate">查询汇率</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQryExchangeRate(QryExchangeRateField^ pQryExchangeRate, int nRequestID);

		/// <summary>
		/// 请求查询二级代理操作员银期权限
		/// </summary>
		/// <param name="pQrySecAgentACIDMap">二级代理操作员银期权限查询</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQrySecAgentACIDMap(QrySecAgentACIDMapField^ pQrySecAgentACIDMap, int nRequestID);

		/// <summary>
		/// 请求查询产品报价汇率
		/// </summary>
		/// <param name="pQryProductExchRate">产品报价汇率查询</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQryProductExchRate(QryProductExchRateField^ pQryProductExchRate, int nRequestID);

		/// <summary>
		/// 请求查询产品组
		/// </summary>
		/// <param name="pQryProductGroup">查询产品组</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQryProductGroup(QryProductGroupField^ pQryProductGroup, int nRequestID);

		/// <summary>
		/// 请求查询做市商合约手续费率
		/// </summary>
		/// <param name="pQryMMInstrumentCommissionRate">查询做市商合约手续费率</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQryMMInstrumentCommissionRate(QryMMInstrumentCommissionRateField^ pQryMMInstrumentCommissionRate, int nRequestID);

		/// <summary>
		/// 请求查询做市商期权合约手续费
		/// </summary>
		/// <param name="pQryMMOptionInstrCommRate">做市商期权手续费率查询</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQryMMOptionInstrCommRate(QryMMOptionInstrCommRateField^ pQryMMOptionInstrCommRate, int nRequestID);

		/// <summary>
		/// 请求查询报单手续费
		/// </summary>
		/// <param name="pQryInstrumentOrderCommRate">报单手续费率查询</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQryInstrumentOrderCommRate(QryInstrumentOrderCommRateField^ pQryInstrumentOrderCommRate, int nRequestID);

		/// <summary>
		/// 请求查询资金账户
		/// </summary>
		/// <param name="pQryTradingAccount">查询资金账户</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQrySecAgentTradingAccount(QryTradingAccountField^ pQryTradingAccount, int nRequestID);

		/// <summary>
		/// 请求查询二级代理商资金校验模式
		/// </summary>
		/// <param name="pQrySecAgentCheckMode">查询二级代理商资金校验模式</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQrySecAgentCheckMode(QrySecAgentCheckModeField^ pQrySecAgentCheckMode, int nRequestID);

		/// <summary>
		/// 请求查询二级代理商信息
		/// </summary>
		/// <param name="pQrySecAgentTradeInfo">查询二级代理商信息</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQrySecAgentTradeInfo(QrySecAgentTradeInfoField^ pQrySecAgentTradeInfo, int nRequestID);

		/// <summary>
		/// 请求查询期权交易成本
		/// </summary>
		/// <param name="pQryOptionInstrTradeCost">期权交易成本查询</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQryOptionInstrTradeCost(QryOptionInstrTradeCostField^ pQryOptionInstrTradeCost, int nRequestID);

		/// <summary>
		/// 请求查询期权合约手续费
		/// </summary>
		/// <param name="pQryOptionInstrCommRate">期权手续费率查询</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQryOptionInstrCommRate(QryOptionInstrCommRateField^ pQryOptionInstrCommRate, int nRequestID);

		/// <summary>
		/// 请求查询执行宣告
		/// </summary>
		/// <param name="pQryExecOrder">执行宣告查询</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQryExecOrder(QryExecOrderField^ pQryExecOrder, int nRequestID);

		/// <summary>
		/// 请求查询询价
		/// </summary>
		/// <param name="pQryForQuote">询价查询</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQryForQuote(QryForQuoteField^ pQryForQuote, int nRequestID);

		/// <summary>
		/// 请求查询报价
		/// </summary>
		/// <param name="pQryQuote">报价查询</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQryQuote(QryQuoteField^ pQryQuote, int nRequestID);

		/// <summary>
		/// 请求查询期权自对冲
		/// </summary>
		/// <param name="pQryOptionSelfClose">期权自对冲查询</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQryOptionSelfClose(QryOptionSelfCloseField^ pQryOptionSelfClose, int nRequestID);

		/// <summary>
		/// 请求查询投资单元
		/// </summary>
		/// <param name="pQryInvestUnit">查询投资单元</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQryInvestUnit(QryInvestUnitField^ pQryInvestUnit, int nRequestID);

		/// <summary>
		/// 请求查询组合合约安全系数
		/// </summary>
		/// <param name="pQryCombInstrumentGuard">组合合约安全系数查询</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQryCombInstrumentGuard(QryCombInstrumentGuardField^ pQryCombInstrumentGuard, int nRequestID);

		/// <summary>
		/// 请求查询申请组合
		/// </summary>
		/// <param name="pQryCombAction">申请组合查询</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQryCombAction(QryCombActionField^ pQryCombAction, int nRequestID);

		/// <summary>
		/// 请求查询转帐流水
		/// </summary>
		/// <param name="pQryTransferSerial">请求查询转帐流水</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQryTransferSerial(QryTransferSerialField^ pQryTransferSerial, int nRequestID);

		/// <summary>
		/// 请求查询银期签约关系
		/// </summary>
		/// <param name="pQryAccountregister">请求查询银期签约关系</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQryAccountregister(QryAccountregisterField^ pQryAccountregister, int nRequestID);

		/// <summary>
		/// 请求查询签约银行
		/// </summary>
		/// <param name="pQryContractBank">查询签约银行请求</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQryContractBank(QryContractBankField^ pQryContractBank, int nRequestID);

		/// <summary>
		/// 请求查询预埋单
		/// </summary>
		/// <param name="pQryParkedOrder">查询预埋单</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQryParkedOrder(QryParkedOrderField^ pQryParkedOrder, int nRequestID);

		/// <summary>
		/// 请求查询预埋撤单
		/// </summary>
		/// <param name="pQryParkedOrderAction">查询预埋撤单</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQryParkedOrderAction(QryParkedOrderActionField^ pQryParkedOrderAction, int nRequestID);

		/// <summary>
		/// 请求查询交易通知
		/// </summary>
		/// <param name="pQryTradingNotice">查询交易事件通知</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQryTradingNotice(QryTradingNoticeField^ pQryTradingNotice, int nRequestID);

		/// <summary>
		/// 请求查询经纪公司交易参数
		/// </summary>
		/// <param name="pQryBrokerTradingParams">查询经纪公司交易参数</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQryBrokerTradingParams(QryBrokerTradingParamsField^ pQryBrokerTradingParams, int nRequestID);

		/// <summary>
		/// 请求查询经纪公司交易算法
		/// </summary>
		/// <param name="pQryBrokerTradingAlgos">查询经纪公司交易算法</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQryBrokerTradingAlgos(QryBrokerTradingAlgosField^ pQryBrokerTradingAlgos, int nRequestID);

		/// <summary>
		/// 请求查询监控中心用户令牌
		/// </summary>
		/// <param name="pQueryCFMMCTradingAccountToken">查询监控中心用户令牌</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQueryCFMMCTradingAccountToken(QueryCFMMCTradingAccountTokenField^ pQueryCFMMCTradingAccountToken, int nRequestID);

		/// <summary>
		/// 期货发起银行资金转期货请求
		/// </summary>
		/// <param name="pReqTransfer">转账请求</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqFromBankToFutureByFuture(ReqTransferField^ pReqTransfer, int nRequestID);

		/// <summary>
		/// 期货发起期货资金转银行请求
		/// </summary>
		/// <param name="pReqTransfer">转账请求</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqFromFutureToBankByFuture(ReqTransferField^ pReqTransfer, int nRequestID);

		/// <summary>
		/// 期货发起查询银行余额请求
		/// </summary>
		/// <param name="pReqQueryAccount">查询账户信息请求</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQueryBankAccountMoneyByFuture(ReqQueryAccountField^ pReqQueryAccount, int nRequestID);

		/// <summary>
		/// 请求查询分类合约
		/// </summary>
		/// <param name="pQryClassifiedInstrument">查询分类合约</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQryClassifiedInstrument(QryClassifiedInstrumentField^ pQryClassifiedInstrument, int nRequestID);

		/// <summary>
		/// 请求组合优惠比例
		/// </summary>
		/// <param name="pQryCombPromotionParam">查询组合优惠比例</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQryCombPromotionParam(QryCombPromotionParamField^ pQryCombPromotionParam, int nRequestID);

		/// <summary>
		/// 投资者风险结算持仓查询
		/// </summary>
		/// <param name="pQryRiskSettleInvstPosition">投资者风险结算持仓查询</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQryRiskSettleInvstPosition(QryRiskSettleInvstPositionField^ pQryRiskSettleInvstPosition, int nRequestID);

		/// <summary>
		/// 风险结算产品查询
		/// </summary>
		/// <param name="pQryRiskSettleProductStatus">风险结算产品查询</param>
		/// <param name="nRequestID">请求ID</param>
		inline virtual int ReqQryRiskSettleProductStatus(QryRiskSettleProductStatusField^ pQryRiskSettleProductStatus, int nRequestID);
	};
}
