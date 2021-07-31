#pragma once
#include "pch.h"

#include "Delegates.h"
#include "CTraderSpi.h"

using namespace PhoenixCTP::TraderDelegates;


namespace PhoenixCTP
{
	ref class TraderApi;

	ref class TraderSpi
	{
	public:
		CThostFtdcTraderSpi* pCSpi;

		TraderApi^ Api;

		inline TraderSpi();

		inline TraderSpi(TraderApi^ pTraderApi);

		inline void SetApi(TraderApi^ pTraderApi);
		
		/// <summary>
		/// 客户端与交易后台建立起通信连接事件，用于同步调用响应函数
		/// </summary>
		event DOnFrontConnected^ FrontConnected;

		/// <summary>
		/// 当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
		/// 该方法会自动生成参数引发<seealso cref="FrontConnected">FrontConnected</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		inline virtual void OnFrontConnected();

		/// <summary>
		/// 当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
		/// 该方法使用外传参数引发<seealso cref="FrontConnected">FrontConnected</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnFrontConnected(TraderSpi^ sender, FrontConnectedArgs^ e);

		/// <summary>
		/// 0x2003 收到错误报文事件，用于同步调用响应函数
		/// </summary>
		event DOnFrontDisconnected^ FrontDisconnected;

		/// <summary>
		/// 0x2003 收到错误报文
		/// 该方法会自动生成参数引发<seealso cref="FrontDisconnected">FrontDisconnected</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="nReason"></param>
		inline virtual void OnFrontDisconnected(int nReason);

		/// <summary>
		/// 0x2003 收到错误报文
		/// 该方法使用外传参数引发<seealso cref="FrontDisconnected">FrontDisconnected</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnFrontDisconnected(TraderSpi^ sender, FrontDisconnectedArgs^ e);

		/// <summary>
		/// @param nTimeLapse 距离上次接收报文的时间事件，用于同步调用响应函数
		/// </summary>
		event DOnHeartBeatWarning^ HeartBeatWarning;

		/// <summary>
		/// @param nTimeLapse 距离上次接收报文的时间
		/// 该方法会自动生成参数引发<seealso cref="HeartBeatWarning">HeartBeatWarning</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="nTimeLapse"></param>
		inline virtual void OnHeartBeatWarning(int nTimeLapse);

		/// <summary>
		/// @param nTimeLapse 距离上次接收报文的时间
		/// 该方法使用外传参数引发<seealso cref="HeartBeatWarning">HeartBeatWarning</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnHeartBeatWarning(TraderSpi^ sender, HeartBeatWarningArgs^ e);

		/// <summary>
		/// 客户端认证响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspAuthenticate^ RspAuthenticate;

		/// <summary>
		/// 客户端认证响应
		/// 该方法会自动生成参数引发<seealso cref="RspAuthenticate">RspAuthenticate</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pRspAuthenticateField">客户端认证响应</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspAuthenticate(RspAuthenticateField^ pRspAuthenticateField, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 客户端认证响应
		/// 该方法使用外传参数引发<seealso cref="RspAuthenticate">RspAuthenticate</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspAuthenticate(TraderSpi^ sender, RspAuthenticateArgs^ e);

		/// <summary>
		/// 登录请求响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspUserLogin^ RspUserLogin;

		/// <summary>
		/// 登录请求响应
		/// 该方法会自动生成参数引发<seealso cref="RspUserLogin">RspUserLogin</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pRspUserLogin">用户登录应答</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspUserLogin(RspUserLoginField^ pRspUserLogin, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 登录请求响应
		/// 该方法使用外传参数引发<seealso cref="RspUserLogin">RspUserLogin</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspUserLogin(TraderSpi^ sender, RspUserLoginArgs^ e);

		/// <summary>
		/// 登出请求响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspUserLogout^ RspUserLogout;

		/// <summary>
		/// 登出请求响应
		/// 该方法会自动生成参数引发<seealso cref="RspUserLogout">RspUserLogout</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pUserLogout">用户登出请求</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspUserLogout(UserLogoutField^ pUserLogout, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 登出请求响应
		/// 该方法使用外传参数引发<seealso cref="RspUserLogout">RspUserLogout</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspUserLogout(TraderSpi^ sender, RspUserLogoutArgs^ e);

		/// <summary>
		/// 用户口令更新请求响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspUserPasswordUpdate^ RspUserPasswordUpdate;

		/// <summary>
		/// 用户口令更新请求响应
		/// 该方法会自动生成参数引发<seealso cref="RspUserPasswordUpdate">RspUserPasswordUpdate</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pUserPasswordUpdate">用户口令变更</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspUserPasswordUpdate(UserPasswordUpdateField^ pUserPasswordUpdate, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 用户口令更新请求响应
		/// 该方法使用外传参数引发<seealso cref="RspUserPasswordUpdate">RspUserPasswordUpdate</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspUserPasswordUpdate(TraderSpi^ sender, RspUserPasswordUpdateArgs^ e);

		/// <summary>
		/// 资金账户口令更新请求响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspTradingAccountPasswordUpdate^ RspTradingAccountPasswordUpdate;

		/// <summary>
		/// 资金账户口令更新请求响应
		/// 该方法会自动生成参数引发<seealso cref="RspTradingAccountPasswordUpdate">RspTradingAccountPasswordUpdate</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pTradingAccountPasswordUpdate">资金账户口令变更域</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspTradingAccountPasswordUpdate(TradingAccountPasswordUpdateField^ pTradingAccountPasswordUpdate, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 资金账户口令更新请求响应
		/// 该方法使用外传参数引发<seealso cref="RspTradingAccountPasswordUpdate">RspTradingAccountPasswordUpdate</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspTradingAccountPasswordUpdate(TraderSpi^ sender, RspTradingAccountPasswordUpdateArgs^ e);

		/// <summary>
		/// 查询用户当前支持的认证模式的回复事件，用于同步调用响应函数
		/// </summary>
		event DOnRspUserAuthMethod^ RspUserAuthMethod;

		/// <summary>
		/// 查询用户当前支持的认证模式的回复
		/// 该方法会自动生成参数引发<seealso cref="RspUserAuthMethod">RspUserAuthMethod</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pRspUserAuthMethod">用户发出获取安全安全登陆方法回复</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspUserAuthMethod(RspUserAuthMethodField^ pRspUserAuthMethod, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 查询用户当前支持的认证模式的回复
		/// 该方法使用外传参数引发<seealso cref="RspUserAuthMethod">RspUserAuthMethod</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspUserAuthMethod(TraderSpi^ sender, RspUserAuthMethodArgs^ e);

		/// <summary>
		/// 获取图形验证码请求的回复事件，用于同步调用响应函数
		/// </summary>
		event DOnRspGenUserCaptcha^ RspGenUserCaptcha;

		/// <summary>
		/// 获取图形验证码请求的回复
		/// 该方法会自动生成参数引发<seealso cref="RspGenUserCaptcha">RspGenUserCaptcha</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pRspGenUserCaptcha">生成的图片验证码信息</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspGenUserCaptcha(RspGenUserCaptchaField^ pRspGenUserCaptcha, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 获取图形验证码请求的回复
		/// 该方法使用外传参数引发<seealso cref="RspGenUserCaptcha">RspGenUserCaptcha</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspGenUserCaptcha(TraderSpi^ sender, RspGenUserCaptchaArgs^ e);

		/// <summary>
		/// 获取短信验证码请求的回复事件，用于同步调用响应函数
		/// </summary>
		event DOnRspGenUserText^ RspGenUserText;

		/// <summary>
		/// 获取短信验证码请求的回复
		/// 该方法会自动生成参数引发<seealso cref="RspGenUserText">RspGenUserText</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pRspGenUserText">短信验证码生成的回复</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspGenUserText(RspGenUserTextField^ pRspGenUserText, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 获取短信验证码请求的回复
		/// 该方法使用外传参数引发<seealso cref="RspGenUserText">RspGenUserText</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspGenUserText(TraderSpi^ sender, RspGenUserTextArgs^ e);

		/// <summary>
		/// 报单录入请求响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspOrderInsert^ RspOrderInsert;

		/// <summary>
		/// 报单录入请求响应
		/// 该方法会自动生成参数引发<seealso cref="RspOrderInsert">RspOrderInsert</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pInputOrder">输入报单</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspOrderInsert(InputOrderField^ pInputOrder, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 报单录入请求响应
		/// 该方法使用外传参数引发<seealso cref="RspOrderInsert">RspOrderInsert</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspOrderInsert(TraderSpi^ sender, RspOrderInsertArgs^ e);

		/// <summary>
		/// 预埋单录入请求响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspParkedOrderInsert^ RspParkedOrderInsert;

		/// <summary>
		/// 预埋单录入请求响应
		/// 该方法会自动生成参数引发<seealso cref="RspParkedOrderInsert">RspParkedOrderInsert</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pParkedOrder">预埋单</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspParkedOrderInsert(ParkedOrderField^ pParkedOrder, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 预埋单录入请求响应
		/// 该方法使用外传参数引发<seealso cref="RspParkedOrderInsert">RspParkedOrderInsert</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspParkedOrderInsert(TraderSpi^ sender, RspParkedOrderInsertArgs^ e);

		/// <summary>
		/// 预埋撤单录入请求响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspParkedOrderAction^ RspParkedOrderAction;

		/// <summary>
		/// 预埋撤单录入请求响应
		/// 该方法会自动生成参数引发<seealso cref="RspParkedOrderAction">RspParkedOrderAction</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pParkedOrderAction">输入预埋单操作</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspParkedOrderAction(ParkedOrderActionField^ pParkedOrderAction, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 预埋撤单录入请求响应
		/// 该方法使用外传参数引发<seealso cref="RspParkedOrderAction">RspParkedOrderAction</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspParkedOrderAction(TraderSpi^ sender, RspParkedOrderActionArgs^ e);

		/// <summary>
		/// 报单操作请求响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspOrderAction^ RspOrderAction;

		/// <summary>
		/// 报单操作请求响应
		/// 该方法会自动生成参数引发<seealso cref="RspOrderAction">RspOrderAction</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pInputOrderAction">输入报单操作</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspOrderAction(InputOrderActionField^ pInputOrderAction, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 报单操作请求响应
		/// 该方法使用外传参数引发<seealso cref="RspOrderAction">RspOrderAction</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspOrderAction(TraderSpi^ sender, RspOrderActionArgs^ e);

		/// <summary>
		/// 查询最大报单数量响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQryMaxOrderVolume^ RspQryMaxOrderVolume;

		/// <summary>
		/// 查询最大报单数量响应
		/// 该方法会自动生成参数引发<seealso cref="RspQryMaxOrderVolume">RspQryMaxOrderVolume</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pQryMaxOrderVolume">查询最大报单数量</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryMaxOrderVolume(QryMaxOrderVolumeField^ pQryMaxOrderVolume, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 查询最大报单数量响应
		/// 该方法使用外传参数引发<seealso cref="RspQryMaxOrderVolume">RspQryMaxOrderVolume</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQryMaxOrderVolume(TraderSpi^ sender, RspQryMaxOrderVolumeArgs^ e);

		/// <summary>
		/// 投资者结算结果确认响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspSettlementInfoConfirm^ RspSettlementInfoConfirm;

		/// <summary>
		/// 投资者结算结果确认响应
		/// 该方法会自动生成参数引发<seealso cref="RspSettlementInfoConfirm">RspSettlementInfoConfirm</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pSettlementInfoConfirm">投资者结算结果确认信息</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspSettlementInfoConfirm(SettlementInfoConfirmField^ pSettlementInfoConfirm, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 投资者结算结果确认响应
		/// 该方法使用外传参数引发<seealso cref="RspSettlementInfoConfirm">RspSettlementInfoConfirm</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspSettlementInfoConfirm(TraderSpi^ sender, RspSettlementInfoConfirmArgs^ e);

		/// <summary>
		/// 删除预埋单响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspRemoveParkedOrder^ RspRemoveParkedOrder;

		/// <summary>
		/// 删除预埋单响应
		/// 该方法会自动生成参数引发<seealso cref="RspRemoveParkedOrder">RspRemoveParkedOrder</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pRemoveParkedOrder">删除预埋单</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspRemoveParkedOrder(RemoveParkedOrderField^ pRemoveParkedOrder, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 删除预埋单响应
		/// 该方法使用外传参数引发<seealso cref="RspRemoveParkedOrder">RspRemoveParkedOrder</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspRemoveParkedOrder(TraderSpi^ sender, RspRemoveParkedOrderArgs^ e);

		/// <summary>
		/// 删除预埋撤单响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspRemoveParkedOrderAction^ RspRemoveParkedOrderAction;

		/// <summary>
		/// 删除预埋撤单响应
		/// 该方法会自动生成参数引发<seealso cref="RspRemoveParkedOrderAction">RspRemoveParkedOrderAction</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pRemoveParkedOrderAction">删除预埋撤单</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspRemoveParkedOrderAction(RemoveParkedOrderActionField^ pRemoveParkedOrderAction, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 删除预埋撤单响应
		/// 该方法使用外传参数引发<seealso cref="RspRemoveParkedOrderAction">RspRemoveParkedOrderAction</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspRemoveParkedOrderAction(TraderSpi^ sender, RspRemoveParkedOrderActionArgs^ e);

		/// <summary>
		/// 执行宣告录入请求响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspExecOrderInsert^ RspExecOrderInsert;

		/// <summary>
		/// 执行宣告录入请求响应
		/// 该方法会自动生成参数引发<seealso cref="RspExecOrderInsert">RspExecOrderInsert</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pInputExecOrder">输入的执行宣告</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspExecOrderInsert(InputExecOrderField^ pInputExecOrder, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 执行宣告录入请求响应
		/// 该方法使用外传参数引发<seealso cref="RspExecOrderInsert">RspExecOrderInsert</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspExecOrderInsert(TraderSpi^ sender, RspExecOrderInsertArgs^ e);

		/// <summary>
		/// 执行宣告操作请求响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspExecOrderAction^ RspExecOrderAction;

		/// <summary>
		/// 执行宣告操作请求响应
		/// 该方法会自动生成参数引发<seealso cref="RspExecOrderAction">RspExecOrderAction</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pInputExecOrderAction">输入执行宣告操作</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspExecOrderAction(InputExecOrderActionField^ pInputExecOrderAction, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 执行宣告操作请求响应
		/// 该方法使用外传参数引发<seealso cref="RspExecOrderAction">RspExecOrderAction</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspExecOrderAction(TraderSpi^ sender, RspExecOrderActionArgs^ e);

		/// <summary>
		/// 询价录入请求响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspForQuoteInsert^ RspForQuoteInsert;

		/// <summary>
		/// 询价录入请求响应
		/// 该方法会自动生成参数引发<seealso cref="RspForQuoteInsert">RspForQuoteInsert</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pInputForQuote">输入的询价</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspForQuoteInsert(InputForQuoteField^ pInputForQuote, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 询价录入请求响应
		/// 该方法使用外传参数引发<seealso cref="RspForQuoteInsert">RspForQuoteInsert</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspForQuoteInsert(TraderSpi^ sender, RspForQuoteInsertArgs^ e);

		/// <summary>
		/// 报价录入请求响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQuoteInsert^ RspQuoteInsert;

		/// <summary>
		/// 报价录入请求响应
		/// 该方法会自动生成参数引发<seealso cref="RspQuoteInsert">RspQuoteInsert</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pInputQuote">输入的报价</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQuoteInsert(InputQuoteField^ pInputQuote, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 报价录入请求响应
		/// 该方法使用外传参数引发<seealso cref="RspQuoteInsert">RspQuoteInsert</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQuoteInsert(TraderSpi^ sender, RspQuoteInsertArgs^ e);

		/// <summary>
		/// 报价操作请求响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQuoteAction^ RspQuoteAction;

		/// <summary>
		/// 报价操作请求响应
		/// 该方法会自动生成参数引发<seealso cref="RspQuoteAction">RspQuoteAction</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pInputQuoteAction">输入报价操作</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQuoteAction(InputQuoteActionField^ pInputQuoteAction, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 报价操作请求响应
		/// 该方法使用外传参数引发<seealso cref="RspQuoteAction">RspQuoteAction</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQuoteAction(TraderSpi^ sender, RspQuoteActionArgs^ e);

		/// <summary>
		/// 批量报单操作请求响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspBatchOrderAction^ RspBatchOrderAction;

		/// <summary>
		/// 批量报单操作请求响应
		/// 该方法会自动生成参数引发<seealso cref="RspBatchOrderAction">RspBatchOrderAction</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pInputBatchOrderAction">输入批量报单操作</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspBatchOrderAction(InputBatchOrderActionField^ pInputBatchOrderAction, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 批量报单操作请求响应
		/// 该方法使用外传参数引发<seealso cref="RspBatchOrderAction">RspBatchOrderAction</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspBatchOrderAction(TraderSpi^ sender, RspBatchOrderActionArgs^ e);

		/// <summary>
		/// 期权自对冲录入请求响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspOptionSelfCloseInsert^ RspOptionSelfCloseInsert;

		/// <summary>
		/// 期权自对冲录入请求响应
		/// 该方法会自动生成参数引发<seealso cref="RspOptionSelfCloseInsert">RspOptionSelfCloseInsert</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pInputOptionSelfClose">输入的期权自对冲</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspOptionSelfCloseInsert(InputOptionSelfCloseField^ pInputOptionSelfClose, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 期权自对冲录入请求响应
		/// 该方法使用外传参数引发<seealso cref="RspOptionSelfCloseInsert">RspOptionSelfCloseInsert</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspOptionSelfCloseInsert(TraderSpi^ sender, RspOptionSelfCloseInsertArgs^ e);

		/// <summary>
		/// 期权自对冲操作请求响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspOptionSelfCloseAction^ RspOptionSelfCloseAction;

		/// <summary>
		/// 期权自对冲操作请求响应
		/// 该方法会自动生成参数引发<seealso cref="RspOptionSelfCloseAction">RspOptionSelfCloseAction</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pInputOptionSelfCloseAction">输入期权自对冲操作</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspOptionSelfCloseAction(InputOptionSelfCloseActionField^ pInputOptionSelfCloseAction, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 期权自对冲操作请求响应
		/// 该方法使用外传参数引发<seealso cref="RspOptionSelfCloseAction">RspOptionSelfCloseAction</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspOptionSelfCloseAction(TraderSpi^ sender, RspOptionSelfCloseActionArgs^ e);

		/// <summary>
		/// 申请组合录入请求响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspCombActionInsert^ RspCombActionInsert;

		/// <summary>
		/// 申请组合录入请求响应
		/// 该方法会自动生成参数引发<seealso cref="RspCombActionInsert">RspCombActionInsert</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pInputCombAction">输入的申请组合</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspCombActionInsert(InputCombActionField^ pInputCombAction, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 申请组合录入请求响应
		/// 该方法使用外传参数引发<seealso cref="RspCombActionInsert">RspCombActionInsert</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspCombActionInsert(TraderSpi^ sender, RspCombActionInsertArgs^ e);

		/// <summary>
		/// 请求查询报单响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQryOrder^ RspQryOrder;

		/// <summary>
		/// 请求查询报单响应
		/// 该方法会自动生成参数引发<seealso cref="RspQryOrder">RspQryOrder</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pOrder">报单</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryOrder(OrderField^ pOrder, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询报单响应
		/// 该方法使用外传参数引发<seealso cref="RspQryOrder">RspQryOrder</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQryOrder(TraderSpi^ sender, RspQryOrderArgs^ e);

		/// <summary>
		/// 请求查询成交响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQryTrade^ RspQryTrade;

		/// <summary>
		/// 请求查询成交响应
		/// 该方法会自动生成参数引发<seealso cref="RspQryTrade">RspQryTrade</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pTrade">成交</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryTrade(TradeField^ pTrade, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询成交响应
		/// 该方法使用外传参数引发<seealso cref="RspQryTrade">RspQryTrade</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQryTrade(TraderSpi^ sender, RspQryTradeArgs^ e);

		/// <summary>
		/// 请求查询投资者持仓响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQryInvestorPosition^ RspQryInvestorPosition;

		/// <summary>
		/// 请求查询投资者持仓响应
		/// 该方法会自动生成参数引发<seealso cref="RspQryInvestorPosition">RspQryInvestorPosition</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pInvestorPosition">投资者持仓</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryInvestorPosition(InvestorPositionField^ pInvestorPosition, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询投资者持仓响应
		/// 该方法使用外传参数引发<seealso cref="RspQryInvestorPosition">RspQryInvestorPosition</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQryInvestorPosition(TraderSpi^ sender, RspQryInvestorPositionArgs^ e);

		/// <summary>
		/// 请求查询资金账户响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQryTradingAccount^ RspQryTradingAccount;

		/// <summary>
		/// 请求查询资金账户响应
		/// 该方法会自动生成参数引发<seealso cref="RspQryTradingAccount">RspQryTradingAccount</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pTradingAccount">资金账户</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryTradingAccount(TradingAccountField^ pTradingAccount, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询资金账户响应
		/// 该方法使用外传参数引发<seealso cref="RspQryTradingAccount">RspQryTradingAccount</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQryTradingAccount(TraderSpi^ sender, RspQryTradingAccountArgs^ e);

		/// <summary>
		/// 请求查询投资者响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQryInvestor^ RspQryInvestor;

		/// <summary>
		/// 请求查询投资者响应
		/// 该方法会自动生成参数引发<seealso cref="RspQryInvestor">RspQryInvestor</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pInvestor">投资者</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryInvestor(InvestorField^ pInvestor, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询投资者响应
		/// 该方法使用外传参数引发<seealso cref="RspQryInvestor">RspQryInvestor</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQryInvestor(TraderSpi^ sender, RspQryInvestorArgs^ e);

		/// <summary>
		/// 请求查询交易编码响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQryTradingCode^ RspQryTradingCode;

		/// <summary>
		/// 请求查询交易编码响应
		/// 该方法会自动生成参数引发<seealso cref="RspQryTradingCode">RspQryTradingCode</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pTradingCode">交易编码</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryTradingCode(TradingCodeField^ pTradingCode, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询交易编码响应
		/// 该方法使用外传参数引发<seealso cref="RspQryTradingCode">RspQryTradingCode</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQryTradingCode(TraderSpi^ sender, RspQryTradingCodeArgs^ e);

		/// <summary>
		/// 请求查询合约保证金率响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQryInstrumentMarginRate^ RspQryInstrumentMarginRate;

		/// <summary>
		/// 请求查询合约保证金率响应
		/// 该方法会自动生成参数引发<seealso cref="RspQryInstrumentMarginRate">RspQryInstrumentMarginRate</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pInstrumentMarginRate">合约保证金率</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryInstrumentMarginRate(InstrumentMarginRateField^ pInstrumentMarginRate, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询合约保证金率响应
		/// 该方法使用外传参数引发<seealso cref="RspQryInstrumentMarginRate">RspQryInstrumentMarginRate</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQryInstrumentMarginRate(TraderSpi^ sender, RspQryInstrumentMarginRateArgs^ e);

		/// <summary>
		/// 请求查询合约手续费率响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQryInstrumentCommissionRate^ RspQryInstrumentCommissionRate;

		/// <summary>
		/// 请求查询合约手续费率响应
		/// 该方法会自动生成参数引发<seealso cref="RspQryInstrumentCommissionRate">RspQryInstrumentCommissionRate</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pInstrumentCommissionRate">合约手续费率</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryInstrumentCommissionRate(InstrumentCommissionRateField^ pInstrumentCommissionRate, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询合约手续费率响应
		/// 该方法使用外传参数引发<seealso cref="RspQryInstrumentCommissionRate">RspQryInstrumentCommissionRate</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQryInstrumentCommissionRate(TraderSpi^ sender, RspQryInstrumentCommissionRateArgs^ e);

		/// <summary>
		/// 请求查询交易所响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQryExchange^ RspQryExchange;

		/// <summary>
		/// 请求查询交易所响应
		/// 该方法会自动生成参数引发<seealso cref="RspQryExchange">RspQryExchange</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pExchange">交易所</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryExchange(ExchangeField^ pExchange, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询交易所响应
		/// 该方法使用外传参数引发<seealso cref="RspQryExchange">RspQryExchange</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQryExchange(TraderSpi^ sender, RspQryExchangeArgs^ e);

		/// <summary>
		/// 请求查询产品响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQryProduct^ RspQryProduct;

		/// <summary>
		/// 请求查询产品响应
		/// 该方法会自动生成参数引发<seealso cref="RspQryProduct">RspQryProduct</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pProduct">产品</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryProduct(ProductField^ pProduct, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询产品响应
		/// 该方法使用外传参数引发<seealso cref="RspQryProduct">RspQryProduct</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQryProduct(TraderSpi^ sender, RspQryProductArgs^ e);

		/// <summary>
		/// 请求查询合约响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQryInstrument^ RspQryInstrument;

		/// <summary>
		/// 请求查询合约响应
		/// 该方法会自动生成参数引发<seealso cref="RspQryInstrument">RspQryInstrument</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pInstrument">合约</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryInstrument(InstrumentField^ pInstrument, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询合约响应
		/// 该方法使用外传参数引发<seealso cref="RspQryInstrument">RspQryInstrument</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQryInstrument(TraderSpi^ sender, RspQryInstrumentArgs^ e);

		/// <summary>
		/// 请求查询行情响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQryDepthMarketData^ RspQryDepthMarketData;

		/// <summary>
		/// 请求查询行情响应
		/// 该方法会自动生成参数引发<seealso cref="RspQryDepthMarketData">RspQryDepthMarketData</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pDepthMarketData">深度行情</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryDepthMarketData(DepthMarketDataField^ pDepthMarketData, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询行情响应
		/// 该方法使用外传参数引发<seealso cref="RspQryDepthMarketData">RspQryDepthMarketData</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQryDepthMarketData(TraderSpi^ sender, RspQryDepthMarketDataArgs^ e);

		/// <summary>
		/// 请求查询投资者结算结果响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQrySettlementInfo^ RspQrySettlementInfo;

		/// <summary>
		/// 请求查询投资者结算结果响应
		/// 该方法会自动生成参数引发<seealso cref="RspQrySettlementInfo">RspQrySettlementInfo</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pSettlementInfo">投资者结算结果</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQrySettlementInfo(SettlementInfoField^ pSettlementInfo, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询投资者结算结果响应
		/// 该方法使用外传参数引发<seealso cref="RspQrySettlementInfo">RspQrySettlementInfo</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQrySettlementInfo(TraderSpi^ sender, RspQrySettlementInfoArgs^ e);

		/// <summary>
		/// 请求查询转帐银行响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQryTransferBank^ RspQryTransferBank;

		/// <summary>
		/// 请求查询转帐银行响应
		/// 该方法会自动生成参数引发<seealso cref="RspQryTransferBank">RspQryTransferBank</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pTransferBank">转帐银行</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryTransferBank(TransferBankField^ pTransferBank, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询转帐银行响应
		/// 该方法使用外传参数引发<seealso cref="RspQryTransferBank">RspQryTransferBank</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQryTransferBank(TraderSpi^ sender, RspQryTransferBankArgs^ e);

		/// <summary>
		/// 请求查询投资者持仓明细响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQryInvestorPositionDetail^ RspQryInvestorPositionDetail;

		/// <summary>
		/// 请求查询投资者持仓明细响应
		/// 该方法会自动生成参数引发<seealso cref="RspQryInvestorPositionDetail">RspQryInvestorPositionDetail</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pInvestorPositionDetail">投资者持仓明细</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryInvestorPositionDetail(InvestorPositionDetailField^ pInvestorPositionDetail, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询投资者持仓明细响应
		/// 该方法使用外传参数引发<seealso cref="RspQryInvestorPositionDetail">RspQryInvestorPositionDetail</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQryInvestorPositionDetail(TraderSpi^ sender, RspQryInvestorPositionDetailArgs^ e);

		/// <summary>
		/// 请求查询客户通知响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQryNotice^ RspQryNotice;

		/// <summary>
		/// 请求查询客户通知响应
		/// 该方法会自动生成参数引发<seealso cref="RspQryNotice">RspQryNotice</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pNotice">客户通知</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryNotice(NoticeField^ pNotice, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询客户通知响应
		/// 该方法使用外传参数引发<seealso cref="RspQryNotice">RspQryNotice</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQryNotice(TraderSpi^ sender, RspQryNoticeArgs^ e);

		/// <summary>
		/// 请求查询结算信息确认响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQrySettlementInfoConfirm^ RspQrySettlementInfoConfirm;

		/// <summary>
		/// 请求查询结算信息确认响应
		/// 该方法会自动生成参数引发<seealso cref="RspQrySettlementInfoConfirm">RspQrySettlementInfoConfirm</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pSettlementInfoConfirm">投资者结算结果确认信息</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQrySettlementInfoConfirm(SettlementInfoConfirmField^ pSettlementInfoConfirm, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询结算信息确认响应
		/// 该方法使用外传参数引发<seealso cref="RspQrySettlementInfoConfirm">RspQrySettlementInfoConfirm</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQrySettlementInfoConfirm(TraderSpi^ sender, RspQrySettlementInfoConfirmArgs^ e);

		/// <summary>
		/// 请求查询投资者持仓明细响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQryInvestorPositionCombineDetail^ RspQryInvestorPositionCombineDetail;

		/// <summary>
		/// 请求查询投资者持仓明细响应
		/// 该方法会自动生成参数引发<seealso cref="RspQryInvestorPositionCombineDetail">RspQryInvestorPositionCombineDetail</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pInvestorPositionCombineDetail">投资者组合持仓明细</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryInvestorPositionCombineDetail(InvestorPositionCombineDetailField^ pInvestorPositionCombineDetail, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询投资者持仓明细响应
		/// 该方法使用外传参数引发<seealso cref="RspQryInvestorPositionCombineDetail">RspQryInvestorPositionCombineDetail</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQryInvestorPositionCombineDetail(TraderSpi^ sender, RspQryInvestorPositionCombineDetailArgs^ e);

		/// <summary>
		/// 查询保证金监管系统经纪公司资金账户密钥响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQryCFMMCTradingAccountKey^ RspQryCFMMCTradingAccountKey;

		/// <summary>
		/// 查询保证金监管系统经纪公司资金账户密钥响应
		/// 该方法会自动生成参数引发<seealso cref="RspQryCFMMCTradingAccountKey">RspQryCFMMCTradingAccountKey</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pCFMMCTradingAccountKey">保证金监管系统经纪公司资金账户密钥</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryCFMMCTradingAccountKey(CFMMCTradingAccountKeyField^ pCFMMCTradingAccountKey, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 查询保证金监管系统经纪公司资金账户密钥响应
		/// 该方法使用外传参数引发<seealso cref="RspQryCFMMCTradingAccountKey">RspQryCFMMCTradingAccountKey</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQryCFMMCTradingAccountKey(TraderSpi^ sender, RspQryCFMMCTradingAccountKeyArgs^ e);

		/// <summary>
		/// 请求查询仓单折抵信息响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQryEWarrantOffset^ RspQryEWarrantOffset;

		/// <summary>
		/// 请求查询仓单折抵信息响应
		/// 该方法会自动生成参数引发<seealso cref="RspQryEWarrantOffset">RspQryEWarrantOffset</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pEWarrantOffset">仓单折抵信息</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryEWarrantOffset(EWarrantOffsetField^ pEWarrantOffset, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询仓单折抵信息响应
		/// 该方法使用外传参数引发<seealso cref="RspQryEWarrantOffset">RspQryEWarrantOffset</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQryEWarrantOffset(TraderSpi^ sender, RspQryEWarrantOffsetArgs^ e);

		/// <summary>
		/// 请求查询投资者品种跨品种保证金响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQryInvestorProductGroupMargin^ RspQryInvestorProductGroupMargin;

		/// <summary>
		/// 请求查询投资者品种跨品种保证金响应
		/// 该方法会自动生成参数引发<seealso cref="RspQryInvestorProductGroupMargin">RspQryInvestorProductGroupMargin</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pInvestorProductGroupMargin">投资者品种跨品种保证金</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryInvestorProductGroupMargin(InvestorProductGroupMarginField^ pInvestorProductGroupMargin, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询投资者品种跨品种保证金响应
		/// 该方法使用外传参数引发<seealso cref="RspQryInvestorProductGroupMargin">RspQryInvestorProductGroupMargin</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQryInvestorProductGroupMargin(TraderSpi^ sender, RspQryInvestorProductGroupMarginArgs^ e);

		/// <summary>
		/// 请求查询交易所保证金率响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQryExchangeMarginRate^ RspQryExchangeMarginRate;

		/// <summary>
		/// 请求查询交易所保证金率响应
		/// 该方法会自动生成参数引发<seealso cref="RspQryExchangeMarginRate">RspQryExchangeMarginRate</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pExchangeMarginRate">交易所保证金率</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryExchangeMarginRate(ExchangeMarginRateField^ pExchangeMarginRate, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询交易所保证金率响应
		/// 该方法使用外传参数引发<seealso cref="RspQryExchangeMarginRate">RspQryExchangeMarginRate</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQryExchangeMarginRate(TraderSpi^ sender, RspQryExchangeMarginRateArgs^ e);

		/// <summary>
		/// 请求查询交易所调整保证金率响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQryExchangeMarginRateAdjust^ RspQryExchangeMarginRateAdjust;

		/// <summary>
		/// 请求查询交易所调整保证金率响应
		/// 该方法会自动生成参数引发<seealso cref="RspQryExchangeMarginRateAdjust">RspQryExchangeMarginRateAdjust</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pExchangeMarginRateAdjust">交易所保证金率调整</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryExchangeMarginRateAdjust(ExchangeMarginRateAdjustField^ pExchangeMarginRateAdjust, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询交易所调整保证金率响应
		/// 该方法使用外传参数引发<seealso cref="RspQryExchangeMarginRateAdjust">RspQryExchangeMarginRateAdjust</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQryExchangeMarginRateAdjust(TraderSpi^ sender, RspQryExchangeMarginRateAdjustArgs^ e);

		/// <summary>
		/// 请求查询汇率响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQryExchangeRate^ RspQryExchangeRate;

		/// <summary>
		/// 请求查询汇率响应
		/// 该方法会自动生成参数引发<seealso cref="RspQryExchangeRate">RspQryExchangeRate</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pExchangeRate">汇率</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryExchangeRate(ExchangeRateField^ pExchangeRate, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询汇率响应
		/// 该方法使用外传参数引发<seealso cref="RspQryExchangeRate">RspQryExchangeRate</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQryExchangeRate(TraderSpi^ sender, RspQryExchangeRateArgs^ e);

		/// <summary>
		/// 请求查询二级代理操作员银期权限响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQrySecAgentACIDMap^ RspQrySecAgentACIDMap;

		/// <summary>
		/// 请求查询二级代理操作员银期权限响应
		/// 该方法会自动生成参数引发<seealso cref="RspQrySecAgentACIDMap">RspQrySecAgentACIDMap</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pSecAgentACIDMap">二级代理操作员银期权限</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQrySecAgentACIDMap(SecAgentACIDMapField^ pSecAgentACIDMap, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询二级代理操作员银期权限响应
		/// 该方法使用外传参数引发<seealso cref="RspQrySecAgentACIDMap">RspQrySecAgentACIDMap</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQrySecAgentACIDMap(TraderSpi^ sender, RspQrySecAgentACIDMapArgs^ e);

		/// <summary>
		/// 请求查询产品报价汇率事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQryProductExchRate^ RspQryProductExchRate;

		/// <summary>
		/// 请求查询产品报价汇率
		/// 该方法会自动生成参数引发<seealso cref="RspQryProductExchRate">RspQryProductExchRate</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pProductExchRate">产品报价汇率</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryProductExchRate(ProductExchRateField^ pProductExchRate, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询产品报价汇率
		/// 该方法使用外传参数引发<seealso cref="RspQryProductExchRate">RspQryProductExchRate</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQryProductExchRate(TraderSpi^ sender, RspQryProductExchRateArgs^ e);

		/// <summary>
		/// 请求查询产品组事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQryProductGroup^ RspQryProductGroup;

		/// <summary>
		/// 请求查询产品组
		/// 该方法会自动生成参数引发<seealso cref="RspQryProductGroup">RspQryProductGroup</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pProductGroup">投资者品种跨品种保证金产品组</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryProductGroup(ProductGroupField^ pProductGroup, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询产品组
		/// 该方法使用外传参数引发<seealso cref="RspQryProductGroup">RspQryProductGroup</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQryProductGroup(TraderSpi^ sender, RspQryProductGroupArgs^ e);

		/// <summary>
		/// 请求查询做市商合约手续费率响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQryMMInstrumentCommissionRate^ RspQryMMInstrumentCommissionRate;

		/// <summary>
		/// 请求查询做市商合约手续费率响应
		/// 该方法会自动生成参数引发<seealso cref="RspQryMMInstrumentCommissionRate">RspQryMMInstrumentCommissionRate</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pMMInstrumentCommissionRate">做市商合约手续费率</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryMMInstrumentCommissionRate(MMInstrumentCommissionRateField^ pMMInstrumentCommissionRate, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询做市商合约手续费率响应
		/// 该方法使用外传参数引发<seealso cref="RspQryMMInstrumentCommissionRate">RspQryMMInstrumentCommissionRate</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQryMMInstrumentCommissionRate(TraderSpi^ sender, RspQryMMInstrumentCommissionRateArgs^ e);

		/// <summary>
		/// 请求查询做市商期权合约手续费响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQryMMOptionInstrCommRate^ RspQryMMOptionInstrCommRate;

		/// <summary>
		/// 请求查询做市商期权合约手续费响应
		/// 该方法会自动生成参数引发<seealso cref="RspQryMMOptionInstrCommRate">RspQryMMOptionInstrCommRate</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pMMOptionInstrCommRate">当前做市商期权合约手续费的详细内容</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryMMOptionInstrCommRate(MMOptionInstrCommRateField^ pMMOptionInstrCommRate, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询做市商期权合约手续费响应
		/// 该方法使用外传参数引发<seealso cref="RspQryMMOptionInstrCommRate">RspQryMMOptionInstrCommRate</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQryMMOptionInstrCommRate(TraderSpi^ sender, RspQryMMOptionInstrCommRateArgs^ e);

		/// <summary>
		/// 请求查询报单手续费响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQryInstrumentOrderCommRate^ RspQryInstrumentOrderCommRate;

		/// <summary>
		/// 请求查询报单手续费响应
		/// 该方法会自动生成参数引发<seealso cref="RspQryInstrumentOrderCommRate">RspQryInstrumentOrderCommRate</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pInstrumentOrderCommRate">当前报单手续费的详细内容</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryInstrumentOrderCommRate(InstrumentOrderCommRateField^ pInstrumentOrderCommRate, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询报单手续费响应
		/// 该方法使用外传参数引发<seealso cref="RspQryInstrumentOrderCommRate">RspQryInstrumentOrderCommRate</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQryInstrumentOrderCommRate(TraderSpi^ sender, RspQryInstrumentOrderCommRateArgs^ e);

		/// <summary>
		/// 请求查询资金账户响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQrySecAgentTradingAccount^ RspQrySecAgentTradingAccount;

		/// <summary>
		/// 请求查询资金账户响应
		/// 该方法会自动生成参数引发<seealso cref="RspQrySecAgentTradingAccount">RspQrySecAgentTradingAccount</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pTradingAccount">资金账户</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQrySecAgentTradingAccount(TradingAccountField^ pTradingAccount, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询资金账户响应
		/// 该方法使用外传参数引发<seealso cref="RspQrySecAgentTradingAccount">RspQrySecAgentTradingAccount</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQrySecAgentTradingAccount(TraderSpi^ sender, RspQrySecAgentTradingAccountArgs^ e);

		/// <summary>
		/// 请求查询二级代理商资金校验模式响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQrySecAgentCheckMode^ RspQrySecAgentCheckMode;

		/// <summary>
		/// 请求查询二级代理商资金校验模式响应
		/// 该方法会自动生成参数引发<seealso cref="RspQrySecAgentCheckMode">RspQrySecAgentCheckMode</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pSecAgentCheckMode">二级代理商资金校验模式</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQrySecAgentCheckMode(SecAgentCheckModeField^ pSecAgentCheckMode, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询二级代理商资金校验模式响应
		/// 该方法使用外传参数引发<seealso cref="RspQrySecAgentCheckMode">RspQrySecAgentCheckMode</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQrySecAgentCheckMode(TraderSpi^ sender, RspQrySecAgentCheckModeArgs^ e);

		/// <summary>
		/// 请求查询二级代理商信息响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQrySecAgentTradeInfo^ RspQrySecAgentTradeInfo;

		/// <summary>
		/// 请求查询二级代理商信息响应
		/// 该方法会自动生成参数引发<seealso cref="RspQrySecAgentTradeInfo">RspQrySecAgentTradeInfo</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pSecAgentTradeInfo">二级代理商信息</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQrySecAgentTradeInfo(SecAgentTradeInfoField^ pSecAgentTradeInfo, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询二级代理商信息响应
		/// 该方法使用外传参数引发<seealso cref="RspQrySecAgentTradeInfo">RspQrySecAgentTradeInfo</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQrySecAgentTradeInfo(TraderSpi^ sender, RspQrySecAgentTradeInfoArgs^ e);

		/// <summary>
		/// 请求查询期权交易成本响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQryOptionInstrTradeCost^ RspQryOptionInstrTradeCost;

		/// <summary>
		/// 请求查询期权交易成本响应
		/// 该方法会自动生成参数引发<seealso cref="RspQryOptionInstrTradeCost">RspQryOptionInstrTradeCost</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pOptionInstrTradeCost">期权交易成本</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryOptionInstrTradeCost(OptionInstrTradeCostField^ pOptionInstrTradeCost, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询期权交易成本响应
		/// 该方法使用外传参数引发<seealso cref="RspQryOptionInstrTradeCost">RspQryOptionInstrTradeCost</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQryOptionInstrTradeCost(TraderSpi^ sender, RspQryOptionInstrTradeCostArgs^ e);

		/// <summary>
		/// 请求查询期权合约手续费响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQryOptionInstrCommRate^ RspQryOptionInstrCommRate;

		/// <summary>
		/// 请求查询期权合约手续费响应
		/// 该方法会自动生成参数引发<seealso cref="RspQryOptionInstrCommRate">RspQryOptionInstrCommRate</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pOptionInstrCommRate">当前期权合约手续费的详细内容</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryOptionInstrCommRate(OptionInstrCommRateField^ pOptionInstrCommRate, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询期权合约手续费响应
		/// 该方法使用外传参数引发<seealso cref="RspQryOptionInstrCommRate">RspQryOptionInstrCommRate</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQryOptionInstrCommRate(TraderSpi^ sender, RspQryOptionInstrCommRateArgs^ e);

		/// <summary>
		/// 请求查询执行宣告响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQryExecOrder^ RspQryExecOrder;

		/// <summary>
		/// 请求查询执行宣告响应
		/// 该方法会自动生成参数引发<seealso cref="RspQryExecOrder">RspQryExecOrder</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pExecOrder">执行宣告</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryExecOrder(ExecOrderField^ pExecOrder, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询执行宣告响应
		/// 该方法使用外传参数引发<seealso cref="RspQryExecOrder">RspQryExecOrder</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQryExecOrder(TraderSpi^ sender, RspQryExecOrderArgs^ e);

		/// <summary>
		/// 请求查询询价响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQryForQuote^ RspQryForQuote;

		/// <summary>
		/// 请求查询询价响应
		/// 该方法会自动生成参数引发<seealso cref="RspQryForQuote">RspQryForQuote</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pForQuote">询价</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryForQuote(ForQuoteField^ pForQuote, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询询价响应
		/// 该方法使用外传参数引发<seealso cref="RspQryForQuote">RspQryForQuote</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQryForQuote(TraderSpi^ sender, RspQryForQuoteArgs^ e);

		/// <summary>
		/// 请求查询报价响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQryQuote^ RspQryQuote;

		/// <summary>
		/// 请求查询报价响应
		/// 该方法会自动生成参数引发<seealso cref="RspQryQuote">RspQryQuote</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pQuote">报价</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryQuote(QuoteField^ pQuote, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询报价响应
		/// 该方法使用外传参数引发<seealso cref="RspQryQuote">RspQryQuote</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQryQuote(TraderSpi^ sender, RspQryQuoteArgs^ e);

		/// <summary>
		/// 请求查询期权自对冲响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQryOptionSelfClose^ RspQryOptionSelfClose;

		/// <summary>
		/// 请求查询期权自对冲响应
		/// 该方法会自动生成参数引发<seealso cref="RspQryOptionSelfClose">RspQryOptionSelfClose</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pOptionSelfClose">期权自对冲</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryOptionSelfClose(OptionSelfCloseField^ pOptionSelfClose, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询期权自对冲响应
		/// 该方法使用外传参数引发<seealso cref="RspQryOptionSelfClose">RspQryOptionSelfClose</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQryOptionSelfClose(TraderSpi^ sender, RspQryOptionSelfCloseArgs^ e);

		/// <summary>
		/// 请求查询投资单元响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQryInvestUnit^ RspQryInvestUnit;

		/// <summary>
		/// 请求查询投资单元响应
		/// 该方法会自动生成参数引发<seealso cref="RspQryInvestUnit">RspQryInvestUnit</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pInvestUnit">投资单元</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryInvestUnit(InvestUnitField^ pInvestUnit, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询投资单元响应
		/// 该方法使用外传参数引发<seealso cref="RspQryInvestUnit">RspQryInvestUnit</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQryInvestUnit(TraderSpi^ sender, RspQryInvestUnitArgs^ e);

		/// <summary>
		/// 请求查询组合合约安全系数响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQryCombInstrumentGuard^ RspQryCombInstrumentGuard;

		/// <summary>
		/// 请求查询组合合约安全系数响应
		/// 该方法会自动生成参数引发<seealso cref="RspQryCombInstrumentGuard">RspQryCombInstrumentGuard</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pCombInstrumentGuard">组合合约安全系数</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryCombInstrumentGuard(CombInstrumentGuardField^ pCombInstrumentGuard, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询组合合约安全系数响应
		/// 该方法使用外传参数引发<seealso cref="RspQryCombInstrumentGuard">RspQryCombInstrumentGuard</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQryCombInstrumentGuard(TraderSpi^ sender, RspQryCombInstrumentGuardArgs^ e);

		/// <summary>
		/// 请求查询申请组合响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQryCombAction^ RspQryCombAction;

		/// <summary>
		/// 请求查询申请组合响应
		/// 该方法会自动生成参数引发<seealso cref="RspQryCombAction">RspQryCombAction</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pCombAction">申请组合</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryCombAction(CombActionField^ pCombAction, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询申请组合响应
		/// 该方法使用外传参数引发<seealso cref="RspQryCombAction">RspQryCombAction</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQryCombAction(TraderSpi^ sender, RspQryCombActionArgs^ e);

		/// <summary>
		/// 请求查询转帐流水响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQryTransferSerial^ RspQryTransferSerial;

		/// <summary>
		/// 请求查询转帐流水响应
		/// 该方法会自动生成参数引发<seealso cref="RspQryTransferSerial">RspQryTransferSerial</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pTransferSerial">银期转账交易流水表</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryTransferSerial(TransferSerialField^ pTransferSerial, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询转帐流水响应
		/// 该方法使用外传参数引发<seealso cref="RspQryTransferSerial">RspQryTransferSerial</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQryTransferSerial(TraderSpi^ sender, RspQryTransferSerialArgs^ e);

		/// <summary>
		/// 请求查询银期签约关系响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQryAccountregister^ RspQryAccountregister;

		/// <summary>
		/// 请求查询银期签约关系响应
		/// 该方法会自动生成参数引发<seealso cref="RspQryAccountregister">RspQryAccountregister</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pAccountregister">客户开销户信息表</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryAccountregister(AccountregisterField^ pAccountregister, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询银期签约关系响应
		/// 该方法使用外传参数引发<seealso cref="RspQryAccountregister">RspQryAccountregister</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQryAccountregister(TraderSpi^ sender, RspQryAccountregisterArgs^ e);

		/// <summary>
		/// 错误应答事件，用于同步调用响应函数
		/// </summary>
		event DOnRspError^ RspError;

		/// <summary>
		/// 错误应答
		/// 该方法会自动生成参数引发<seealso cref="RspError">RspError</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspError(RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 错误应答
		/// 该方法使用外传参数引发<seealso cref="RspError">RspError</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspError(TraderSpi^ sender, RspErrorArgs^ e);

		/// <summary>
		/// 报单通知事件，用于同步调用响应函数
		/// </summary>
		event DOnRtnOrder^ RtnOrder;

		/// <summary>
		/// 报单通知
		/// 该方法会自动生成参数引发<seealso cref="RtnOrder">RtnOrder</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pOrder">报单</param>
		inline virtual void OnRtnOrder(OrderField^ pOrder);

		/// <summary>
		/// 报单通知
		/// 该方法使用外传参数引发<seealso cref="RtnOrder">RtnOrder</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRtnOrder(TraderSpi^ sender, RtnOrderArgs^ e);

		/// <summary>
		/// 成交通知事件，用于同步调用响应函数
		/// </summary>
		event DOnRtnTrade^ RtnTrade;

		/// <summary>
		/// 成交通知
		/// 该方法会自动生成参数引发<seealso cref="RtnTrade">RtnTrade</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pTrade">成交</param>
		inline virtual void OnRtnTrade(TradeField^ pTrade);

		/// <summary>
		/// 成交通知
		/// 该方法使用外传参数引发<seealso cref="RtnTrade">RtnTrade</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRtnTrade(TraderSpi^ sender, RtnTradeArgs^ e);

		/// <summary>
		/// 报单录入错误回报事件，用于同步调用响应函数
		/// </summary>
		event DOnErrRtnOrderInsert^ ErrRtnOrderInsert;

		/// <summary>
		/// 报单录入错误回报
		/// 该方法会自动生成参数引发<seealso cref="ErrRtnOrderInsert">ErrRtnOrderInsert</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pInputOrder">输入报单</param>
		/// <param name="pRspInfo">响应信息</param>
		inline virtual void OnErrRtnOrderInsert(InputOrderField^ pInputOrder, RspInfoField^ pRspInfo);

		/// <summary>
		/// 报单录入错误回报
		/// 该方法使用外传参数引发<seealso cref="ErrRtnOrderInsert">ErrRtnOrderInsert</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnErrRtnOrderInsert(TraderSpi^ sender, ErrRtnOrderInsertArgs^ e);

		/// <summary>
		/// 报单操作错误回报事件，用于同步调用响应函数
		/// </summary>
		event DOnErrRtnOrderAction^ ErrRtnOrderAction;

		/// <summary>
		/// 报单操作错误回报
		/// 该方法会自动生成参数引发<seealso cref="ErrRtnOrderAction">ErrRtnOrderAction</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pOrderAction">报单操作</param>
		/// <param name="pRspInfo">响应信息</param>
		inline virtual void OnErrRtnOrderAction(OrderActionField^ pOrderAction, RspInfoField^ pRspInfo);

		/// <summary>
		/// 报单操作错误回报
		/// 该方法使用外传参数引发<seealso cref="ErrRtnOrderAction">ErrRtnOrderAction</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnErrRtnOrderAction(TraderSpi^ sender, ErrRtnOrderActionArgs^ e);

		/// <summary>
		/// 合约交易状态通知事件，用于同步调用响应函数
		/// </summary>
		event DOnRtnInstrumentStatus^ RtnInstrumentStatus;

		/// <summary>
		/// 合约交易状态通知
		/// 该方法会自动生成参数引发<seealso cref="RtnInstrumentStatus">RtnInstrumentStatus</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pInstrumentStatus">合约状态</param>
		inline virtual void OnRtnInstrumentStatus(InstrumentStatusField^ pInstrumentStatus);

		/// <summary>
		/// 合约交易状态通知
		/// 该方法使用外传参数引发<seealso cref="RtnInstrumentStatus">RtnInstrumentStatus</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRtnInstrumentStatus(TraderSpi^ sender, RtnInstrumentStatusArgs^ e);

		/// <summary>
		/// 交易所公告通知事件，用于同步调用响应函数
		/// </summary>
		event DOnRtnBulletin^ RtnBulletin;

		/// <summary>
		/// 交易所公告通知
		/// 该方法会自动生成参数引发<seealso cref="RtnBulletin">RtnBulletin</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pBulletin">交易所公告</param>
		inline virtual void OnRtnBulletin(BulletinField^ pBulletin);

		/// <summary>
		/// 交易所公告通知
		/// 该方法使用外传参数引发<seealso cref="RtnBulletin">RtnBulletin</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRtnBulletin(TraderSpi^ sender, RtnBulletinArgs^ e);

		/// <summary>
		/// 交易通知事件，用于同步调用响应函数
		/// </summary>
		event DOnRtnTradingNotice^ RtnTradingNotice;

		/// <summary>
		/// 交易通知
		/// 该方法会自动生成参数引发<seealso cref="RtnTradingNotice">RtnTradingNotice</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pTradingNoticeInfo">用户事件通知信息</param>
		inline virtual void OnRtnTradingNotice(TradingNoticeInfoField^ pTradingNoticeInfo);

		/// <summary>
		/// 交易通知
		/// 该方法使用外传参数引发<seealso cref="RtnTradingNotice">RtnTradingNotice</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRtnTradingNotice(TraderSpi^ sender, RtnTradingNoticeArgs^ e);

		/// <summary>
		/// 提示条件单校验错误事件，用于同步调用响应函数
		/// </summary>
		event DOnRtnErrorConditionalOrder^ RtnErrorConditionalOrder;

		/// <summary>
		/// 提示条件单校验错误
		/// 该方法会自动生成参数引发<seealso cref="RtnErrorConditionalOrder">RtnErrorConditionalOrder</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pErrorConditionalOrder">查询错误报单操作</param>
		inline virtual void OnRtnErrorConditionalOrder(ErrorConditionalOrderField^ pErrorConditionalOrder);

		/// <summary>
		/// 提示条件单校验错误
		/// 该方法使用外传参数引发<seealso cref="RtnErrorConditionalOrder">RtnErrorConditionalOrder</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRtnErrorConditionalOrder(TraderSpi^ sender, RtnErrorConditionalOrderArgs^ e);

		/// <summary>
		/// 执行宣告通知事件，用于同步调用响应函数
		/// </summary>
		event DOnRtnExecOrder^ RtnExecOrder;

		/// <summary>
		/// 执行宣告通知
		/// 该方法会自动生成参数引发<seealso cref="RtnExecOrder">RtnExecOrder</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pExecOrder">执行宣告</param>
		inline virtual void OnRtnExecOrder(ExecOrderField^ pExecOrder);

		/// <summary>
		/// 执行宣告通知
		/// 该方法使用外传参数引发<seealso cref="RtnExecOrder">RtnExecOrder</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRtnExecOrder(TraderSpi^ sender, RtnExecOrderArgs^ e);

		/// <summary>
		/// 执行宣告录入错误回报事件，用于同步调用响应函数
		/// </summary>
		event DOnErrRtnExecOrderInsert^ ErrRtnExecOrderInsert;

		/// <summary>
		/// 执行宣告录入错误回报
		/// 该方法会自动生成参数引发<seealso cref="ErrRtnExecOrderInsert">ErrRtnExecOrderInsert</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pInputExecOrder">输入的执行宣告</param>
		/// <param name="pRspInfo">响应信息</param>
		inline virtual void OnErrRtnExecOrderInsert(InputExecOrderField^ pInputExecOrder, RspInfoField^ pRspInfo);

		/// <summary>
		/// 执行宣告录入错误回报
		/// 该方法使用外传参数引发<seealso cref="ErrRtnExecOrderInsert">ErrRtnExecOrderInsert</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnErrRtnExecOrderInsert(TraderSpi^ sender, ErrRtnExecOrderInsertArgs^ e);

		/// <summary>
		/// 执行宣告操作错误回报事件，用于同步调用响应函数
		/// </summary>
		event DOnErrRtnExecOrderAction^ ErrRtnExecOrderAction;

		/// <summary>
		/// 执行宣告操作错误回报
		/// 该方法会自动生成参数引发<seealso cref="ErrRtnExecOrderAction">ErrRtnExecOrderAction</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pExecOrderAction">执行宣告操作</param>
		/// <param name="pRspInfo">响应信息</param>
		inline virtual void OnErrRtnExecOrderAction(ExecOrderActionField^ pExecOrderAction, RspInfoField^ pRspInfo);

		/// <summary>
		/// 执行宣告操作错误回报
		/// 该方法使用外传参数引发<seealso cref="ErrRtnExecOrderAction">ErrRtnExecOrderAction</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnErrRtnExecOrderAction(TraderSpi^ sender, ErrRtnExecOrderActionArgs^ e);

		/// <summary>
		/// 询价录入错误回报事件，用于同步调用响应函数
		/// </summary>
		event DOnErrRtnForQuoteInsert^ ErrRtnForQuoteInsert;

		/// <summary>
		/// 询价录入错误回报
		/// 该方法会自动生成参数引发<seealso cref="ErrRtnForQuoteInsert">ErrRtnForQuoteInsert</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pInputForQuote">输入的询价</param>
		/// <param name="pRspInfo">响应信息</param>
		inline virtual void OnErrRtnForQuoteInsert(InputForQuoteField^ pInputForQuote, RspInfoField^ pRspInfo);

		/// <summary>
		/// 询价录入错误回报
		/// 该方法使用外传参数引发<seealso cref="ErrRtnForQuoteInsert">ErrRtnForQuoteInsert</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnErrRtnForQuoteInsert(TraderSpi^ sender, ErrRtnForQuoteInsertArgs^ e);

		/// <summary>
		/// 报价通知事件，用于同步调用响应函数
		/// </summary>
		event DOnRtnQuote^ RtnQuote;

		/// <summary>
		/// 报价通知
		/// 该方法会自动生成参数引发<seealso cref="RtnQuote">RtnQuote</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pQuote">报价</param>
		inline virtual void OnRtnQuote(QuoteField^ pQuote);

		/// <summary>
		/// 报价通知
		/// 该方法使用外传参数引发<seealso cref="RtnQuote">RtnQuote</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRtnQuote(TraderSpi^ sender, RtnQuoteArgs^ e);

		/// <summary>
		/// 报价录入错误回报事件，用于同步调用响应函数
		/// </summary>
		event DOnErrRtnQuoteInsert^ ErrRtnQuoteInsert;

		/// <summary>
		/// 报价录入错误回报
		/// 该方法会自动生成参数引发<seealso cref="ErrRtnQuoteInsert">ErrRtnQuoteInsert</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pInputQuote">输入的报价</param>
		/// <param name="pRspInfo">响应信息</param>
		inline virtual void OnErrRtnQuoteInsert(InputQuoteField^ pInputQuote, RspInfoField^ pRspInfo);

		/// <summary>
		/// 报价录入错误回报
		/// 该方法使用外传参数引发<seealso cref="ErrRtnQuoteInsert">ErrRtnQuoteInsert</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnErrRtnQuoteInsert(TraderSpi^ sender, ErrRtnQuoteInsertArgs^ e);

		/// <summary>
		/// 报价操作错误回报事件，用于同步调用响应函数
		/// </summary>
		event DOnErrRtnQuoteAction^ ErrRtnQuoteAction;

		/// <summary>
		/// 报价操作错误回报
		/// 该方法会自动生成参数引发<seealso cref="ErrRtnQuoteAction">ErrRtnQuoteAction</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pQuoteAction">报价操作</param>
		/// <param name="pRspInfo">响应信息</param>
		inline virtual void OnErrRtnQuoteAction(QuoteActionField^ pQuoteAction, RspInfoField^ pRspInfo);

		/// <summary>
		/// 报价操作错误回报
		/// 该方法使用外传参数引发<seealso cref="ErrRtnQuoteAction">ErrRtnQuoteAction</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnErrRtnQuoteAction(TraderSpi^ sender, ErrRtnQuoteActionArgs^ e);

		/// <summary>
		/// 询价通知事件，用于同步调用响应函数
		/// </summary>
		event DOnRtnForQuoteRsp^ RtnForQuoteRsp;

		/// <summary>
		/// 询价通知
		/// 该方法会自动生成参数引发<seealso cref="RtnForQuoteRsp">RtnForQuoteRsp</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pForQuoteRsp">发给做市商的询价请求</param>
		inline virtual void OnRtnForQuoteRsp(ForQuoteRspField^ pForQuoteRsp);

		/// <summary>
		/// 询价通知
		/// 该方法使用外传参数引发<seealso cref="RtnForQuoteRsp">RtnForQuoteRsp</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRtnForQuoteRsp(TraderSpi^ sender, RtnForQuoteRspArgs^ e);

		/// <summary>
		/// 保证金监控中心用户令牌事件，用于同步调用响应函数
		/// </summary>
		event DOnRtnCFMMCTradingAccountToken^ RtnCFMMCTradingAccountToken;

		/// <summary>
		/// 保证金监控中心用户令牌
		/// 该方法会自动生成参数引发<seealso cref="RtnCFMMCTradingAccountToken">RtnCFMMCTradingAccountToken</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pCFMMCTradingAccountToken">监控中心用户令牌</param>
		inline virtual void OnRtnCFMMCTradingAccountToken(CFMMCTradingAccountTokenField^ pCFMMCTradingAccountToken);

		/// <summary>
		/// 保证金监控中心用户令牌
		/// 该方法使用外传参数引发<seealso cref="RtnCFMMCTradingAccountToken">RtnCFMMCTradingAccountToken</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRtnCFMMCTradingAccountToken(TraderSpi^ sender, RtnCFMMCTradingAccountTokenArgs^ e);

		/// <summary>
		/// 批量报单操作错误回报事件，用于同步调用响应函数
		/// </summary>
		event DOnErrRtnBatchOrderAction^ ErrRtnBatchOrderAction;

		/// <summary>
		/// 批量报单操作错误回报
		/// 该方法会自动生成参数引发<seealso cref="ErrRtnBatchOrderAction">ErrRtnBatchOrderAction</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pBatchOrderAction">批量报单操作</param>
		/// <param name="pRspInfo">响应信息</param>
		inline virtual void OnErrRtnBatchOrderAction(BatchOrderActionField^ pBatchOrderAction, RspInfoField^ pRspInfo);

		/// <summary>
		/// 批量报单操作错误回报
		/// 该方法使用外传参数引发<seealso cref="ErrRtnBatchOrderAction">ErrRtnBatchOrderAction</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnErrRtnBatchOrderAction(TraderSpi^ sender, ErrRtnBatchOrderActionArgs^ e);

		/// <summary>
		/// 期权自对冲通知事件，用于同步调用响应函数
		/// </summary>
		event DOnRtnOptionSelfClose^ RtnOptionSelfClose;

		/// <summary>
		/// 期权自对冲通知
		/// 该方法会自动生成参数引发<seealso cref="RtnOptionSelfClose">RtnOptionSelfClose</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pOptionSelfClose">期权自对冲</param>
		inline virtual void OnRtnOptionSelfClose(OptionSelfCloseField^ pOptionSelfClose);

		/// <summary>
		/// 期权自对冲通知
		/// 该方法使用外传参数引发<seealso cref="RtnOptionSelfClose">RtnOptionSelfClose</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRtnOptionSelfClose(TraderSpi^ sender, RtnOptionSelfCloseArgs^ e);

		/// <summary>
		/// 期权自对冲录入错误回报事件，用于同步调用响应函数
		/// </summary>
		event DOnErrRtnOptionSelfCloseInsert^ ErrRtnOptionSelfCloseInsert;

		/// <summary>
		/// 期权自对冲录入错误回报
		/// 该方法会自动生成参数引发<seealso cref="ErrRtnOptionSelfCloseInsert">ErrRtnOptionSelfCloseInsert</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pInputOptionSelfClose">输入的期权自对冲</param>
		/// <param name="pRspInfo">响应信息</param>
		inline virtual void OnErrRtnOptionSelfCloseInsert(InputOptionSelfCloseField^ pInputOptionSelfClose, RspInfoField^ pRspInfo);

		/// <summary>
		/// 期权自对冲录入错误回报
		/// 该方法使用外传参数引发<seealso cref="ErrRtnOptionSelfCloseInsert">ErrRtnOptionSelfCloseInsert</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnErrRtnOptionSelfCloseInsert(TraderSpi^ sender, ErrRtnOptionSelfCloseInsertArgs^ e);

		/// <summary>
		/// 期权自对冲操作错误回报事件，用于同步调用响应函数
		/// </summary>
		event DOnErrRtnOptionSelfCloseAction^ ErrRtnOptionSelfCloseAction;

		/// <summary>
		/// 期权自对冲操作错误回报
		/// 该方法会自动生成参数引发<seealso cref="ErrRtnOptionSelfCloseAction">ErrRtnOptionSelfCloseAction</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pOptionSelfCloseAction">期权自对冲操作</param>
		/// <param name="pRspInfo">响应信息</param>
		inline virtual void OnErrRtnOptionSelfCloseAction(OptionSelfCloseActionField^ pOptionSelfCloseAction, RspInfoField^ pRspInfo);

		/// <summary>
		/// 期权自对冲操作错误回报
		/// 该方法使用外传参数引发<seealso cref="ErrRtnOptionSelfCloseAction">ErrRtnOptionSelfCloseAction</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnErrRtnOptionSelfCloseAction(TraderSpi^ sender, ErrRtnOptionSelfCloseActionArgs^ e);

		/// <summary>
		/// 申请组合通知事件，用于同步调用响应函数
		/// </summary>
		event DOnRtnCombAction^ RtnCombAction;

		/// <summary>
		/// 申请组合通知
		/// 该方法会自动生成参数引发<seealso cref="RtnCombAction">RtnCombAction</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pCombAction">申请组合</param>
		inline virtual void OnRtnCombAction(CombActionField^ pCombAction);

		/// <summary>
		/// 申请组合通知
		/// 该方法使用外传参数引发<seealso cref="RtnCombAction">RtnCombAction</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRtnCombAction(TraderSpi^ sender, RtnCombActionArgs^ e);

		/// <summary>
		/// 申请组合录入错误回报事件，用于同步调用响应函数
		/// </summary>
		event DOnErrRtnCombActionInsert^ ErrRtnCombActionInsert;

		/// <summary>
		/// 申请组合录入错误回报
		/// 该方法会自动生成参数引发<seealso cref="ErrRtnCombActionInsert">ErrRtnCombActionInsert</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pInputCombAction">输入的申请组合</param>
		/// <param name="pRspInfo">响应信息</param>
		inline virtual void OnErrRtnCombActionInsert(InputCombActionField^ pInputCombAction, RspInfoField^ pRspInfo);

		/// <summary>
		/// 申请组合录入错误回报
		/// 该方法使用外传参数引发<seealso cref="ErrRtnCombActionInsert">ErrRtnCombActionInsert</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnErrRtnCombActionInsert(TraderSpi^ sender, ErrRtnCombActionInsertArgs^ e);

		/// <summary>
		/// 请求查询签约银行响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQryContractBank^ RspQryContractBank;

		/// <summary>
		/// 请求查询签约银行响应
		/// 该方法会自动生成参数引发<seealso cref="RspQryContractBank">RspQryContractBank</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pContractBank">查询签约银行响应</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryContractBank(ContractBankField^ pContractBank, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询签约银行响应
		/// 该方法使用外传参数引发<seealso cref="RspQryContractBank">RspQryContractBank</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQryContractBank(TraderSpi^ sender, RspQryContractBankArgs^ e);

		/// <summary>
		/// 请求查询预埋单响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQryParkedOrder^ RspQryParkedOrder;

		/// <summary>
		/// 请求查询预埋单响应
		/// 该方法会自动生成参数引发<seealso cref="RspQryParkedOrder">RspQryParkedOrder</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pParkedOrder">预埋单</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryParkedOrder(ParkedOrderField^ pParkedOrder, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询预埋单响应
		/// 该方法使用外传参数引发<seealso cref="RspQryParkedOrder">RspQryParkedOrder</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQryParkedOrder(TraderSpi^ sender, RspQryParkedOrderArgs^ e);

		/// <summary>
		/// 请求查询预埋撤单响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQryParkedOrderAction^ RspQryParkedOrderAction;

		/// <summary>
		/// 请求查询预埋撤单响应
		/// 该方法会自动生成参数引发<seealso cref="RspQryParkedOrderAction">RspQryParkedOrderAction</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pParkedOrderAction">输入预埋单操作</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryParkedOrderAction(ParkedOrderActionField^ pParkedOrderAction, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询预埋撤单响应
		/// 该方法使用外传参数引发<seealso cref="RspQryParkedOrderAction">RspQryParkedOrderAction</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQryParkedOrderAction(TraderSpi^ sender, RspQryParkedOrderActionArgs^ e);

		/// <summary>
		/// 请求查询交易通知响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQryTradingNotice^ RspQryTradingNotice;

		/// <summary>
		/// 请求查询交易通知响应
		/// 该方法会自动生成参数引发<seealso cref="RspQryTradingNotice">RspQryTradingNotice</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pTradingNotice">用户事件通知</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryTradingNotice(TradingNoticeField^ pTradingNotice, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询交易通知响应
		/// 该方法使用外传参数引发<seealso cref="RspQryTradingNotice">RspQryTradingNotice</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQryTradingNotice(TraderSpi^ sender, RspQryTradingNoticeArgs^ e);

		/// <summary>
		/// 请求查询经纪公司交易参数响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQryBrokerTradingParams^ RspQryBrokerTradingParams;

		/// <summary>
		/// 请求查询经纪公司交易参数响应
		/// 该方法会自动生成参数引发<seealso cref="RspQryBrokerTradingParams">RspQryBrokerTradingParams</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pBrokerTradingParams">经纪公司交易参数</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryBrokerTradingParams(BrokerTradingParamsField^ pBrokerTradingParams, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询经纪公司交易参数响应
		/// 该方法使用外传参数引发<seealso cref="RspQryBrokerTradingParams">RspQryBrokerTradingParams</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQryBrokerTradingParams(TraderSpi^ sender, RspQryBrokerTradingParamsArgs^ e);

		/// <summary>
		/// 请求查询经纪公司交易算法响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQryBrokerTradingAlgos^ RspQryBrokerTradingAlgos;

		/// <summary>
		/// 请求查询经纪公司交易算法响应
		/// 该方法会自动生成参数引发<seealso cref="RspQryBrokerTradingAlgos">RspQryBrokerTradingAlgos</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pBrokerTradingAlgos">经纪公司交易算法</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryBrokerTradingAlgos(BrokerTradingAlgosField^ pBrokerTradingAlgos, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询经纪公司交易算法响应
		/// 该方法使用外传参数引发<seealso cref="RspQryBrokerTradingAlgos">RspQryBrokerTradingAlgos</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQryBrokerTradingAlgos(TraderSpi^ sender, RspQryBrokerTradingAlgosArgs^ e);

		/// <summary>
		/// 请求查询监控中心用户令牌事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQueryCFMMCTradingAccountToken^ RspQueryCFMMCTradingAccountToken;

		/// <summary>
		/// 请求查询监控中心用户令牌
		/// 该方法会自动生成参数引发<seealso cref="RspQueryCFMMCTradingAccountToken">RspQueryCFMMCTradingAccountToken</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pQueryCFMMCTradingAccountToken">查询监控中心用户令牌</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQueryCFMMCTradingAccountToken(QueryCFMMCTradingAccountTokenField^ pQueryCFMMCTradingAccountToken, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询监控中心用户令牌
		/// 该方法使用外传参数引发<seealso cref="RspQueryCFMMCTradingAccountToken">RspQueryCFMMCTradingAccountToken</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQueryCFMMCTradingAccountToken(TraderSpi^ sender, RspQueryCFMMCTradingAccountTokenArgs^ e);

		/// <summary>
		/// 银行发起银行资金转期货通知事件，用于同步调用响应函数
		/// </summary>
		event DOnRtnFromBankToFutureByBank^ RtnFromBankToFutureByBank;

		/// <summary>
		/// 银行发起银行资金转期货通知
		/// 该方法会自动生成参数引发<seealso cref="RtnFromBankToFutureByBank">RtnFromBankToFutureByBank</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pRspTransfer">银行发起银行资金转期货响应</param>
		inline virtual void OnRtnFromBankToFutureByBank(RspTransferField^ pRspTransfer);

		/// <summary>
		/// 银行发起银行资金转期货通知
		/// 该方法使用外传参数引发<seealso cref="RtnFromBankToFutureByBank">RtnFromBankToFutureByBank</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRtnFromBankToFutureByBank(TraderSpi^ sender, RtnFromBankToFutureByBankArgs^ e);

		/// <summary>
		/// 银行发起期货资金转银行通知事件，用于同步调用响应函数
		/// </summary>
		event DOnRtnFromFutureToBankByBank^ RtnFromFutureToBankByBank;

		/// <summary>
		/// 银行发起期货资金转银行通知
		/// 该方法会自动生成参数引发<seealso cref="RtnFromFutureToBankByBank">RtnFromFutureToBankByBank</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pRspTransfer">银行发起银行资金转期货响应</param>
		inline virtual void OnRtnFromFutureToBankByBank(RspTransferField^ pRspTransfer);

		/// <summary>
		/// 银行发起期货资金转银行通知
		/// 该方法使用外传参数引发<seealso cref="RtnFromFutureToBankByBank">RtnFromFutureToBankByBank</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRtnFromFutureToBankByBank(TraderSpi^ sender, RtnFromFutureToBankByBankArgs^ e);

		/// <summary>
		/// 银行发起冲正银行转期货通知事件，用于同步调用响应函数
		/// </summary>
		event DOnRtnRepealFromBankToFutureByBank^ RtnRepealFromBankToFutureByBank;

		/// <summary>
		/// 银行发起冲正银行转期货通知
		/// 该方法会自动生成参数引发<seealso cref="RtnRepealFromBankToFutureByBank">RtnRepealFromBankToFutureByBank</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pRspRepeal">冲正响应</param>
		inline virtual void OnRtnRepealFromBankToFutureByBank(RspRepealField^ pRspRepeal);

		/// <summary>
		/// 银行发起冲正银行转期货通知
		/// 该方法使用外传参数引发<seealso cref="RtnRepealFromBankToFutureByBank">RtnRepealFromBankToFutureByBank</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRtnRepealFromBankToFutureByBank(TraderSpi^ sender, RtnRepealFromBankToFutureByBankArgs^ e);

		/// <summary>
		/// 银行发起冲正期货转银行通知事件，用于同步调用响应函数
		/// </summary>
		event DOnRtnRepealFromFutureToBankByBank^ RtnRepealFromFutureToBankByBank;

		/// <summary>
		/// 银行发起冲正期货转银行通知
		/// 该方法会自动生成参数引发<seealso cref="RtnRepealFromFutureToBankByBank">RtnRepealFromFutureToBankByBank</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pRspRepeal">冲正响应</param>
		inline virtual void OnRtnRepealFromFutureToBankByBank(RspRepealField^ pRspRepeal);

		/// <summary>
		/// 银行发起冲正期货转银行通知
		/// 该方法使用外传参数引发<seealso cref="RtnRepealFromFutureToBankByBank">RtnRepealFromFutureToBankByBank</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRtnRepealFromFutureToBankByBank(TraderSpi^ sender, RtnRepealFromFutureToBankByBankArgs^ e);

		/// <summary>
		/// 期货发起银行资金转期货通知事件，用于同步调用响应函数
		/// </summary>
		event DOnRtnFromBankToFutureByFuture^ RtnFromBankToFutureByFuture;

		/// <summary>
		/// 期货发起银行资金转期货通知
		/// 该方法会自动生成参数引发<seealso cref="RtnFromBankToFutureByFuture">RtnFromBankToFutureByFuture</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pRspTransfer">银行发起银行资金转期货响应</param>
		inline virtual void OnRtnFromBankToFutureByFuture(RspTransferField^ pRspTransfer);

		/// <summary>
		/// 期货发起银行资金转期货通知
		/// 该方法使用外传参数引发<seealso cref="RtnFromBankToFutureByFuture">RtnFromBankToFutureByFuture</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRtnFromBankToFutureByFuture(TraderSpi^ sender, RtnFromBankToFutureByFutureArgs^ e);

		/// <summary>
		/// 期货发起期货资金转银行通知事件，用于同步调用响应函数
		/// </summary>
		event DOnRtnFromFutureToBankByFuture^ RtnFromFutureToBankByFuture;

		/// <summary>
		/// 期货发起期货资金转银行通知
		/// 该方法会自动生成参数引发<seealso cref="RtnFromFutureToBankByFuture">RtnFromFutureToBankByFuture</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pRspTransfer">银行发起银行资金转期货响应</param>
		inline virtual void OnRtnFromFutureToBankByFuture(RspTransferField^ pRspTransfer);

		/// <summary>
		/// 期货发起期货资金转银行通知
		/// 该方法使用外传参数引发<seealso cref="RtnFromFutureToBankByFuture">RtnFromFutureToBankByFuture</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRtnFromFutureToBankByFuture(TraderSpi^ sender, RtnFromFutureToBankByFutureArgs^ e);

		/// <summary>
		/// 系统运行时期货端手工发起冲正银行转期货请求，银行处理完毕后报盘发回的通知事件，用于同步调用响应函数
		/// </summary>
		event DOnRtnRepealFromBankToFutureByFutureManual^ RtnRepealFromBankToFutureByFutureManual;

		/// <summary>
		/// 系统运行时期货端手工发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
		/// 该方法会自动生成参数引发<seealso cref="RtnRepealFromBankToFutureByFutureManual">RtnRepealFromBankToFutureByFutureManual</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pRspRepeal">冲正响应</param>
		inline virtual void OnRtnRepealFromBankToFutureByFutureManual(RspRepealField^ pRspRepeal);

		/// <summary>
		/// 系统运行时期货端手工发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
		/// 该方法使用外传参数引发<seealso cref="RtnRepealFromBankToFutureByFutureManual">RtnRepealFromBankToFutureByFutureManual</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRtnRepealFromBankToFutureByFutureManual(TraderSpi^ sender, RtnRepealFromBankToFutureByFutureManualArgs^ e);

		/// <summary>
		/// 系统运行时期货端手工发起冲正期货转银行请求，银行处理完毕后报盘发回的通知事件，用于同步调用响应函数
		/// </summary>
		event DOnRtnRepealFromFutureToBankByFutureManual^ RtnRepealFromFutureToBankByFutureManual;

		/// <summary>
		/// 系统运行时期货端手工发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
		/// 该方法会自动生成参数引发<seealso cref="RtnRepealFromFutureToBankByFutureManual">RtnRepealFromFutureToBankByFutureManual</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pRspRepeal">冲正响应</param>
		inline virtual void OnRtnRepealFromFutureToBankByFutureManual(RspRepealField^ pRspRepeal);

		/// <summary>
		/// 系统运行时期货端手工发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
		/// 该方法使用外传参数引发<seealso cref="RtnRepealFromFutureToBankByFutureManual">RtnRepealFromFutureToBankByFutureManual</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRtnRepealFromFutureToBankByFutureManual(TraderSpi^ sender, RtnRepealFromFutureToBankByFutureManualArgs^ e);

		/// <summary>
		/// 期货发起查询银行余额通知事件，用于同步调用响应函数
		/// </summary>
		event DOnRtnQueryBankBalanceByFuture^ RtnQueryBankBalanceByFuture;

		/// <summary>
		/// 期货发起查询银行余额通知
		/// 该方法会自动生成参数引发<seealso cref="RtnQueryBankBalanceByFuture">RtnQueryBankBalanceByFuture</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pNotifyQueryAccount">查询账户信息通知</param>
		inline virtual void OnRtnQueryBankBalanceByFuture(NotifyQueryAccountField^ pNotifyQueryAccount);

		/// <summary>
		/// 期货发起查询银行余额通知
		/// 该方法使用外传参数引发<seealso cref="RtnQueryBankBalanceByFuture">RtnQueryBankBalanceByFuture</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRtnQueryBankBalanceByFuture(TraderSpi^ sender, RtnQueryBankBalanceByFutureArgs^ e);

		/// <summary>
		/// 期货发起银行资金转期货错误回报事件，用于同步调用响应函数
		/// </summary>
		event DOnErrRtnBankToFutureByFuture^ ErrRtnBankToFutureByFuture;

		/// <summary>
		/// 期货发起银行资金转期货错误回报
		/// 该方法会自动生成参数引发<seealso cref="ErrRtnBankToFutureByFuture">ErrRtnBankToFutureByFuture</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pReqTransfer">转账请求</param>
		/// <param name="pRspInfo">响应信息</param>
		inline virtual void OnErrRtnBankToFutureByFuture(ReqTransferField^ pReqTransfer, RspInfoField^ pRspInfo);

		/// <summary>
		/// 期货发起银行资金转期货错误回报
		/// 该方法使用外传参数引发<seealso cref="ErrRtnBankToFutureByFuture">ErrRtnBankToFutureByFuture</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnErrRtnBankToFutureByFuture(TraderSpi^ sender, ErrRtnBankToFutureByFutureArgs^ e);

		/// <summary>
		/// 期货发起期货资金转银行错误回报事件，用于同步调用响应函数
		/// </summary>
		event DOnErrRtnFutureToBankByFuture^ ErrRtnFutureToBankByFuture;

		/// <summary>
		/// 期货发起期货资金转银行错误回报
		/// 该方法会自动生成参数引发<seealso cref="ErrRtnFutureToBankByFuture">ErrRtnFutureToBankByFuture</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pReqTransfer">转账请求</param>
		/// <param name="pRspInfo">响应信息</param>
		inline virtual void OnErrRtnFutureToBankByFuture(ReqTransferField^ pReqTransfer, RspInfoField^ pRspInfo);

		/// <summary>
		/// 期货发起期货资金转银行错误回报
		/// 该方法使用外传参数引发<seealso cref="ErrRtnFutureToBankByFuture">ErrRtnFutureToBankByFuture</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnErrRtnFutureToBankByFuture(TraderSpi^ sender, ErrRtnFutureToBankByFutureArgs^ e);

		/// <summary>
		/// 系统运行时期货端手工发起冲正银行转期货错误回报事件，用于同步调用响应函数
		/// </summary>
		event DOnErrRtnRepealBankToFutureByFutureManual^ ErrRtnRepealBankToFutureByFutureManual;

		/// <summary>
		/// 系统运行时期货端手工发起冲正银行转期货错误回报
		/// 该方法会自动生成参数引发<seealso cref="ErrRtnRepealBankToFutureByFutureManual">ErrRtnRepealBankToFutureByFutureManual</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pReqRepeal">冲正请求</param>
		/// <param name="pRspInfo">响应信息</param>
		inline virtual void OnErrRtnRepealBankToFutureByFutureManual(ReqRepealField^ pReqRepeal, RspInfoField^ pRspInfo);

		/// <summary>
		/// 系统运行时期货端手工发起冲正银行转期货错误回报
		/// 该方法使用外传参数引发<seealso cref="ErrRtnRepealBankToFutureByFutureManual">ErrRtnRepealBankToFutureByFutureManual</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnErrRtnRepealBankToFutureByFutureManual(TraderSpi^ sender, ErrRtnRepealBankToFutureByFutureManualArgs^ e);

		/// <summary>
		/// 系统运行时期货端手工发起冲正期货转银行错误回报事件，用于同步调用响应函数
		/// </summary>
		event DOnErrRtnRepealFutureToBankByFutureManual^ ErrRtnRepealFutureToBankByFutureManual;

		/// <summary>
		/// 系统运行时期货端手工发起冲正期货转银行错误回报
		/// 该方法会自动生成参数引发<seealso cref="ErrRtnRepealFutureToBankByFutureManual">ErrRtnRepealFutureToBankByFutureManual</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pReqRepeal">冲正请求</param>
		/// <param name="pRspInfo">响应信息</param>
		inline virtual void OnErrRtnRepealFutureToBankByFutureManual(ReqRepealField^ pReqRepeal, RspInfoField^ pRspInfo);

		/// <summary>
		/// 系统运行时期货端手工发起冲正期货转银行错误回报
		/// 该方法使用外传参数引发<seealso cref="ErrRtnRepealFutureToBankByFutureManual">ErrRtnRepealFutureToBankByFutureManual</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnErrRtnRepealFutureToBankByFutureManual(TraderSpi^ sender, ErrRtnRepealFutureToBankByFutureManualArgs^ e);

		/// <summary>
		/// 期货发起查询银行余额错误回报事件，用于同步调用响应函数
		/// </summary>
		event DOnErrRtnQueryBankBalanceByFuture^ ErrRtnQueryBankBalanceByFuture;

		/// <summary>
		/// 期货发起查询银行余额错误回报
		/// 该方法会自动生成参数引发<seealso cref="ErrRtnQueryBankBalanceByFuture">ErrRtnQueryBankBalanceByFuture</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pReqQueryAccount">查询账户信息请求</param>
		/// <param name="pRspInfo">响应信息</param>
		inline virtual void OnErrRtnQueryBankBalanceByFuture(ReqQueryAccountField^ pReqQueryAccount, RspInfoField^ pRspInfo);

		/// <summary>
		/// 期货发起查询银行余额错误回报
		/// 该方法使用外传参数引发<seealso cref="ErrRtnQueryBankBalanceByFuture">ErrRtnQueryBankBalanceByFuture</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnErrRtnQueryBankBalanceByFuture(TraderSpi^ sender, ErrRtnQueryBankBalanceByFutureArgs^ e);

		/// <summary>
		/// 期货发起冲正银行转期货请求，银行处理完毕后报盘发回的通知事件，用于同步调用响应函数
		/// </summary>
		event DOnRtnRepealFromBankToFutureByFuture^ RtnRepealFromBankToFutureByFuture;

		/// <summary>
		/// 期货发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
		/// 该方法会自动生成参数引发<seealso cref="RtnRepealFromBankToFutureByFuture">RtnRepealFromBankToFutureByFuture</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pRspRepeal">冲正响应</param>
		inline virtual void OnRtnRepealFromBankToFutureByFuture(RspRepealField^ pRspRepeal);

		/// <summary>
		/// 期货发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
		/// 该方法使用外传参数引发<seealso cref="RtnRepealFromBankToFutureByFuture">RtnRepealFromBankToFutureByFuture</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRtnRepealFromBankToFutureByFuture(TraderSpi^ sender, RtnRepealFromBankToFutureByFutureArgs^ e);

		/// <summary>
		/// 期货发起冲正期货转银行请求，银行处理完毕后报盘发回的通知事件，用于同步调用响应函数
		/// </summary>
		event DOnRtnRepealFromFutureToBankByFuture^ RtnRepealFromFutureToBankByFuture;

		/// <summary>
		/// 期货发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
		/// 该方法会自动生成参数引发<seealso cref="RtnRepealFromFutureToBankByFuture">RtnRepealFromFutureToBankByFuture</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pRspRepeal">冲正响应</param>
		inline virtual void OnRtnRepealFromFutureToBankByFuture(RspRepealField^ pRspRepeal);

		/// <summary>
		/// 期货发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
		/// 该方法使用外传参数引发<seealso cref="RtnRepealFromFutureToBankByFuture">RtnRepealFromFutureToBankByFuture</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRtnRepealFromFutureToBankByFuture(TraderSpi^ sender, RtnRepealFromFutureToBankByFutureArgs^ e);

		/// <summary>
		/// 期货发起银行资金转期货应答事件，用于同步调用响应函数
		/// </summary>
		event DOnRspFromBankToFutureByFuture^ RspFromBankToFutureByFuture;

		/// <summary>
		/// 期货发起银行资金转期货应答
		/// 该方法会自动生成参数引发<seealso cref="RspFromBankToFutureByFuture">RspFromBankToFutureByFuture</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pReqTransfer">转账请求</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspFromBankToFutureByFuture(ReqTransferField^ pReqTransfer, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 期货发起银行资金转期货应答
		/// 该方法使用外传参数引发<seealso cref="RspFromBankToFutureByFuture">RspFromBankToFutureByFuture</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspFromBankToFutureByFuture(TraderSpi^ sender, RspFromBankToFutureByFutureArgs^ e);

		/// <summary>
		/// 期货发起期货资金转银行应答事件，用于同步调用响应函数
		/// </summary>
		event DOnRspFromFutureToBankByFuture^ RspFromFutureToBankByFuture;

		/// <summary>
		/// 期货发起期货资金转银行应答
		/// 该方法会自动生成参数引发<seealso cref="RspFromFutureToBankByFuture">RspFromFutureToBankByFuture</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pReqTransfer">转账请求</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspFromFutureToBankByFuture(ReqTransferField^ pReqTransfer, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 期货发起期货资金转银行应答
		/// 该方法使用外传参数引发<seealso cref="RspFromFutureToBankByFuture">RspFromFutureToBankByFuture</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspFromFutureToBankByFuture(TraderSpi^ sender, RspFromFutureToBankByFutureArgs^ e);

		/// <summary>
		/// 期货发起查询银行余额应答事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQueryBankAccountMoneyByFuture^ RspQueryBankAccountMoneyByFuture;

		/// <summary>
		/// 期货发起查询银行余额应答
		/// 该方法会自动生成参数引发<seealso cref="RspQueryBankAccountMoneyByFuture">RspQueryBankAccountMoneyByFuture</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pReqQueryAccount">查询账户信息请求</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQueryBankAccountMoneyByFuture(ReqQueryAccountField^ pReqQueryAccount, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 期货发起查询银行余额应答
		/// 该方法使用外传参数引发<seealso cref="RspQueryBankAccountMoneyByFuture">RspQueryBankAccountMoneyByFuture</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQueryBankAccountMoneyByFuture(TraderSpi^ sender, RspQueryBankAccountMoneyByFutureArgs^ e);

		/// <summary>
		/// 银行发起银期开户通知事件，用于同步调用响应函数
		/// </summary>
		event DOnRtnOpenAccountByBank^ RtnOpenAccountByBank;

		/// <summary>
		/// 银行发起银期开户通知
		/// 该方法会自动生成参数引发<seealso cref="RtnOpenAccountByBank">RtnOpenAccountByBank</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pOpenAccount">银期开户信息</param>
		inline virtual void OnRtnOpenAccountByBank(OpenAccountField^ pOpenAccount);

		/// <summary>
		/// 银行发起银期开户通知
		/// 该方法使用外传参数引发<seealso cref="RtnOpenAccountByBank">RtnOpenAccountByBank</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRtnOpenAccountByBank(TraderSpi^ sender, RtnOpenAccountByBankArgs^ e);

		/// <summary>
		/// 银行发起银期销户通知事件，用于同步调用响应函数
		/// </summary>
		event DOnRtnCancelAccountByBank^ RtnCancelAccountByBank;

		/// <summary>
		/// 银行发起银期销户通知
		/// 该方法会自动生成参数引发<seealso cref="RtnCancelAccountByBank">RtnCancelAccountByBank</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pCancelAccount">银期销户信息</param>
		inline virtual void OnRtnCancelAccountByBank(CancelAccountField^ pCancelAccount);

		/// <summary>
		/// 银行发起银期销户通知
		/// 该方法使用外传参数引发<seealso cref="RtnCancelAccountByBank">RtnCancelAccountByBank</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRtnCancelAccountByBank(TraderSpi^ sender, RtnCancelAccountByBankArgs^ e);

		/// <summary>
		/// 银行发起变更银行账号通知事件，用于同步调用响应函数
		/// </summary>
		event DOnRtnChangeAccountByBank^ RtnChangeAccountByBank;

		/// <summary>
		/// 银行发起变更银行账号通知
		/// 该方法会自动生成参数引发<seealso cref="RtnChangeAccountByBank">RtnChangeAccountByBank</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pChangeAccount">银期变更银行账号信息</param>
		inline virtual void OnRtnChangeAccountByBank(ChangeAccountField^ pChangeAccount);

		/// <summary>
		/// 银行发起变更银行账号通知
		/// 该方法使用外传参数引发<seealso cref="RtnChangeAccountByBank">RtnChangeAccountByBank</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRtnChangeAccountByBank(TraderSpi^ sender, RtnChangeAccountByBankArgs^ e);

		/// <summary>
		/// 请求查询分类合约响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQryClassifiedInstrument^ RspQryClassifiedInstrument;

		/// <summary>
		/// 请求查询分类合约响应
		/// 该方法会自动生成参数引发<seealso cref="RspQryClassifiedInstrument">RspQryClassifiedInstrument</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pInstrument">合约</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryClassifiedInstrument(InstrumentField^ pInstrument, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求查询分类合约响应
		/// 该方法使用外传参数引发<seealso cref="RspQryClassifiedInstrument">RspQryClassifiedInstrument</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQryClassifiedInstrument(TraderSpi^ sender, RspQryClassifiedInstrumentArgs^ e);

		/// <summary>
		/// 请求组合优惠比例响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQryCombPromotionParam^ RspQryCombPromotionParam;

		/// <summary>
		/// 请求组合优惠比例响应
		/// 该方法会自动生成参数引发<seealso cref="RspQryCombPromotionParam">RspQryCombPromotionParam</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pCombPromotionParam">组合优惠比例</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryCombPromotionParam(CombPromotionParamField^ pCombPromotionParam, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 请求组合优惠比例响应
		/// 该方法使用外传参数引发<seealso cref="RspQryCombPromotionParam">RspQryCombPromotionParam</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQryCombPromotionParam(TraderSpi^ sender, RspQryCombPromotionParamArgs^ e);

		/// <summary>
		/// 投资者风险结算持仓查询响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQryRiskSettleInvstPosition^ RspQryRiskSettleInvstPosition;

		/// <summary>
		/// 投资者风险结算持仓查询响应
		/// 该方法会自动生成参数引发<seealso cref="RspQryRiskSettleInvstPosition">RspQryRiskSettleInvstPosition</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pRiskSettleInvstPosition">投资者风险结算持仓</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryRiskSettleInvstPosition(RiskSettleInvstPositionField^ pRiskSettleInvstPosition, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 投资者风险结算持仓查询响应
		/// 该方法使用外传参数引发<seealso cref="RspQryRiskSettleInvstPosition">RspQryRiskSettleInvstPosition</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQryRiskSettleInvstPosition(TraderSpi^ sender, RspQryRiskSettleInvstPositionArgs^ e);

		/// <summary>
		/// 风险结算产品查询响应事件，用于同步调用响应函数
		/// </summary>
		event DOnRspQryRiskSettleProductStatus^ RspQryRiskSettleProductStatus;

		/// <summary>
		/// 风险结算产品查询响应
		/// 该方法会自动生成参数引发<seealso cref="RspQryRiskSettleProductStatus">RspQryRiskSettleProductStatus</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="pRiskSettleProductStatus">风险品种</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		inline virtual void OnRspQryRiskSettleProductStatus(RiskSettleProductStatusField^ pRiskSettleProductStatus, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

		/// <summary>
		/// 风险结算产品查询响应
		/// 该方法使用外传参数引发<seealso cref="RspQryRiskSettleProductStatus">RspQryRiskSettleProductStatus</seealso>事件,这一事件<b>同步</b>调用响应函数。
		/// </summary>
		/// <param name="sender">引发事件的TraderSpi实例</param>
		/// <param name="e">引发事件参数</param>
		inline virtual void OnRspQryRiskSettleProductStatus(TraderSpi^ sender, RspQryRiskSettleProductStatusArgs^ e);


	};
}
