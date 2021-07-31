#pragma once
#include "ApiStructs.h"

/// <summary>
/// Md部分
/// </summary>
namespace PhoenixCTP
{
	/// <summary>
	/// 用于大多数事件响应参数的基类，包含响应信息、请求/响应ID、响应是否持续信息
	/// </summary>
	public ref class BasicArgs : System::EventArgs
	{
	public:
		RspInfoField^ pRspInfo;
		int nRequestID;
		bool bIsLast;

		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		BasicArgs(RspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
		{
			this->pRspInfo = pRspInfo;
			this->nRequestID = nRequestID;
			this->bIsLast = bIsLast;
		}
	};

	/// <summary>
	/// 当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。事件参数
	/// </summary>
	public ref class FrontConnectedArgs : System::EventArgs
	{
	public:

		/// <summary>
		/// 当客户端与交易后台建立起通信连接事件参数
		/// </summary>
		FrontConnectedArgs()
		{
		}
	};

	
	/// <summary>
	/// 客户端与后台通信连接中断事件参数
	/// </summary>
	/// <param name="nReason">错误原因
	///        0x1001 网络读失败
	///        0x1002 网络写失败
	///        0x2001 接收心跳超时
	///        0x2002 发送心跳失败
	///        0x2003 收到错误报文</param>
	public ref class FrontDisconnectedArgs : System::EventArgs
	{
	public:
		int nReason;

		/// <summary>
		/// 
		/// </summary>
		/// <param name="nReason">错误原因
		///        0x1001 网络读失败
		///        0x1002 网络写失败
		///        0x2001 接收心跳超时
		///        0x2002 发送心跳失败
		///        0x2003 收到错误报文</param>
		FrontDisconnectedArgs(int nReason)
		{
			this->nReason = nReason;
		}
	};

	
	/// <summary>
	/// 心跳超时警告事件参数
	/// </summary>
	public ref class HeartBeatWarningArgs : System::EventArgs
	{
	public:
		int nTimeLapse;

		/// <summary>
		/// 心跳超时警告事件参数
		/// </summary>
		/// <param name="nTimeLapse">距离上次接收到报文的时间</param>
		HeartBeatWarningArgs(int nTimeLapse)
		{
			this->nTimeLapse = nTimeLapse;
		}
	};

	/// <summary>
	/// 登录请求响应事件参数
	/// </summary>
	public ref class RspUserLoginArgs : BasicArgs
	{
	public:
		RspUserLoginField^ pRspUserLogin;

		/// <summary>
		/// 登录请求响应事件参数
		/// </summary>
		/// <param name="pRspUserLogin">用户登录应答</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspUserLoginArgs(RspUserLoginField^ pRspUserLogin, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pRspUserLogin = pRspUserLogin;
		}
	};


	/// <summary>
	/// 登出请求响应事件参数
	/// </summary>
	public ref class RspUserLogoutArgs : BasicArgs
	{
	public:
		UserLogoutField^ pUserLogout;

		/// <summary>
		/// 登出请求响应事件参数
		/// </summary>
		/// <param name="pUserLogout">用户登出请求</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspUserLogoutArgs(UserLogoutField^ pUserLogout, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pUserLogout = pUserLogout;
		}
	};
	
	/// <summary>
	/// 请求查询组播合约响应事件参数
	/// </summary>
	public ref class RspQryMulticastInstrumentArgs : BasicArgs
	{
	public:
		MulticastInstrumentField^ pMulticastInstrument;

		/// <summary>
		/// 请求查询组播合约响应事件参数
		/// </summary>
		/// <param name="pMulticastInstrument">组播合约</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQryMulticastInstrumentArgs(MulticastInstrumentField^ pMulticastInstrument, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pMulticastInstrument = pMulticastInstrument;
		}
	};

	/// <summary>
	/// 错误应答事件参数
	/// </summary>
	public ref class RspErrorArgs : BasicArgs
	{
	public:
		/// <summary>
		/// 错误应答事件参数
		/// </summary>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspErrorArgs(RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
		}
	};

	/// <summary>
	/// 订阅行情、取消订阅行情、订阅询价、取消订阅询价应答事件参数
	/// </summary>
	public ref class SpecificInstrumentEventArgs : BasicArgs
	{
	public:
		SpecificInstrumentField^ pSpecificInstrument;

		/// <summary>
		/// 订阅行情、取消订阅行情、订阅询价、取消订阅询价应答事件参数
		/// </summary>
		/// <param name="pDepthMarketData">指定的合约</param>
		SpecificInstrumentEventArgs(SpecificInstrumentField^ pSpecificInstrument, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast): BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pSpecificInstrument = pSpecificInstrument;
		}
	};

	/// <summary>
	/// 深度行情通知事件参数
	/// </summary>
	public ref class RtnDepthMarketDataArgs : System::EventArgs
	{
	public:
		DepthMarketDataField^ pDepthMarketData;
		/// <summary>
		/// 深度行情通知事件参数
		/// </summary>
		/// <param name="pDepthMarketData">深度行情</param>
		RtnDepthMarketDataArgs(DepthMarketDataField^ pDepthMarketData)
		{
			this->pDepthMarketData = pDepthMarketData;
		}
	};


	/// <summary>
	/// 询价通知事件参数
	/// </summary>
	public ref class RtnForQuoteRspArgs : System::EventArgs
	{
	public:
		ForQuoteRspField^ pForQuoteRsp;

		/// <summary>
		/// 询价通知事件参数
		/// </summary>
		/// <param name="pForQuoteRsp">发给做市商的询价请求</param>
		RtnForQuoteRspArgs(ForQuoteRspField^ pForQuoteRsp)
		{
			this->pForQuoteRsp = pForQuoteRsp;
		}
	};
}

/// <summary>
/// Trader部分
/// </summary>
namespace PhoenixCTP
{


	/// <summary>
	/// 客户端认证响应事件参数
	/// </summary>
	public ref class RspAuthenticateArgs : BasicArgs
	{
	public:
		RspAuthenticateField^ pRspAuthenticateField;

		/// <summary>
		/// 客户端认证响应事件参数
		/// </summary>
		/// <param name="pRspAuthenticateField">客户端认证响应</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspAuthenticateArgs(RspAuthenticateField^ pRspAuthenticateField, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pRspAuthenticateField = pRspAuthenticateField;
		}
	};



	/// <summary>
	/// 用户口令更新请求响应事件参数
	/// </summary>
	public ref class RspUserPasswordUpdateArgs : BasicArgs
	{
	public:
		UserPasswordUpdateField^ pUserPasswordUpdate;

		/// <summary>
		/// 用户口令更新请求响应事件参数
		/// </summary>
		/// <param name="pUserPasswordUpdate">用户口令变更</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspUserPasswordUpdateArgs(UserPasswordUpdateField^ pUserPasswordUpdate, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pUserPasswordUpdate = pUserPasswordUpdate;
		}
	};

	/// <summary>
	/// 资金账户口令更新请求响应事件参数
	/// </summary>
	public ref class RspTradingAccountPasswordUpdateArgs : BasicArgs
	{
	public:
		TradingAccountPasswordUpdateField^ pTradingAccountPasswordUpdate;

		/// <summary>
		/// 资金账户口令更新请求响应事件参数
		/// </summary>
		/// <param name="pTradingAccountPasswordUpdate">资金账户口令变更域</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspTradingAccountPasswordUpdateArgs(TradingAccountPasswordUpdateField^ pTradingAccountPasswordUpdate, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pTradingAccountPasswordUpdate = pTradingAccountPasswordUpdate;
		}
	};

	/// <summary>
	/// 查询用户当前支持的认证模式的回复事件参数
	/// </summary>
	public ref class RspUserAuthMethodArgs : BasicArgs
	{
	public:
		RspUserAuthMethodField^ pRspUserAuthMethod;

		/// <summary>
		/// 查询用户当前支持的认证模式的回复事件参数
		/// </summary>
		/// <param name="pRspUserAuthMethod">用户发出获取安全安全登陆方法回复</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspUserAuthMethodArgs(RspUserAuthMethodField^ pRspUserAuthMethod, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pRspUserAuthMethod = pRspUserAuthMethod;
		}
	};

	/// <summary>
	/// 获取图形验证码请求的回复事件参数
	/// </summary>
	public ref class RspGenUserCaptchaArgs : BasicArgs
	{
	public:
		RspGenUserCaptchaField^ pRspGenUserCaptcha;

		/// <summary>
		/// 获取图形验证码请求的回复事件参数
		/// </summary>
		/// <param name="pRspGenUserCaptcha">生成的图片验证码信息</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspGenUserCaptchaArgs(RspGenUserCaptchaField^ pRspGenUserCaptcha, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pRspGenUserCaptcha = pRspGenUserCaptcha;
		}
	};

	/// <summary>
	/// 获取短信验证码请求的回复事件参数
	/// </summary>
	public ref class RspGenUserTextArgs : BasicArgs
	{
	public:
		RspGenUserTextField^ pRspGenUserText;

		/// <summary>
		/// 获取短信验证码请求的回复事件参数
		/// </summary>
		/// <param name="pRspGenUserText">短信验证码生成的回复</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspGenUserTextArgs(RspGenUserTextField^ pRspGenUserText, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pRspGenUserText = pRspGenUserText;
		}
	};

	/// <summary>
	/// 报单录入请求响应事件参数
	/// </summary>
	public ref class RspOrderInsertArgs : BasicArgs
	{
	public:
		InputOrderField^ pInputOrder;

		/// <summary>
		/// 报单录入请求响应事件参数
		/// </summary>
		/// <param name="pInputOrder">输入报单</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspOrderInsertArgs(InputOrderField^ pInputOrder, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pInputOrder = pInputOrder;
		}
	};

	/// <summary>
	/// 预埋单录入请求响应事件参数
	/// </summary>
	public ref class RspParkedOrderInsertArgs : BasicArgs
	{
	public:
		ParkedOrderField^ pParkedOrder;

		/// <summary>
		/// 预埋单录入请求响应事件参数
		/// </summary>
		/// <param name="pParkedOrder">预埋单</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspParkedOrderInsertArgs(ParkedOrderField^ pParkedOrder, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pParkedOrder = pParkedOrder;
		}
	};

	/// <summary>
	/// 预埋撤单录入请求响应事件参数
	/// </summary>
	public ref class RspParkedOrderActionArgs : BasicArgs
	{
	public:
		ParkedOrderActionField^ pParkedOrderAction;

		/// <summary>
		/// 预埋撤单录入请求响应事件参数
		/// </summary>
		/// <param name="pParkedOrderAction">输入预埋单操作</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspParkedOrderActionArgs(ParkedOrderActionField^ pParkedOrderAction, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pParkedOrderAction = pParkedOrderAction;
		}
	};

	/// <summary>
	/// 报单操作请求响应事件参数
	/// </summary>
	public ref class RspOrderActionArgs : BasicArgs
	{
	public:
		InputOrderActionField^ pInputOrderAction;

		/// <summary>
		/// 报单操作请求响应事件参数
		/// </summary>
		/// <param name="pInputOrderAction">输入报单操作</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspOrderActionArgs(InputOrderActionField^ pInputOrderAction, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pInputOrderAction = pInputOrderAction;
		}
	};

	/// <summary>
	/// 查询最大报单数量响应事件参数
	/// </summary>
	public ref class RspQryMaxOrderVolumeArgs : BasicArgs
	{
	public:
		QryMaxOrderVolumeField^ pQryMaxOrderVolume;

		/// <summary>
		/// 查询最大报单数量响应事件参数
		/// </summary>
		/// <param name="pQryMaxOrderVolume">查询最大报单数量</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQryMaxOrderVolumeArgs(QryMaxOrderVolumeField^ pQryMaxOrderVolume, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pQryMaxOrderVolume = pQryMaxOrderVolume;
		}
	};

	/// <summary>
	/// 投资者结算结果确认响应事件参数
	/// </summary>
	public ref class RspSettlementInfoConfirmArgs : BasicArgs
	{
	public:
		SettlementInfoConfirmField^ pSettlementInfoConfirm;

		/// <summary>
		/// 投资者结算结果确认响应事件参数
		/// </summary>
		/// <param name="pSettlementInfoConfirm">投资者结算结果确认信息</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspSettlementInfoConfirmArgs(SettlementInfoConfirmField^ pSettlementInfoConfirm, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pSettlementInfoConfirm = pSettlementInfoConfirm;
		}
	};

	/// <summary>
	/// 删除预埋单响应事件参数
	/// </summary>
	public ref class RspRemoveParkedOrderArgs : BasicArgs
	{
	public:
		RemoveParkedOrderField^ pRemoveParkedOrder;

		/// <summary>
		/// 删除预埋单响应事件参数
		/// </summary>
		/// <param name="pRemoveParkedOrder">删除预埋单</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspRemoveParkedOrderArgs(RemoveParkedOrderField^ pRemoveParkedOrder, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pRemoveParkedOrder = pRemoveParkedOrder;
		}
	};

	/// <summary>
	/// 删除预埋撤单响应事件参数
	/// </summary>
	public ref class RspRemoveParkedOrderActionArgs : BasicArgs
	{
	public:
		RemoveParkedOrderActionField^ pRemoveParkedOrderAction;

		/// <summary>
		/// 删除预埋撤单响应事件参数
		/// </summary>
		/// <param name="pRemoveParkedOrderAction">删除预埋撤单</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspRemoveParkedOrderActionArgs(RemoveParkedOrderActionField^ pRemoveParkedOrderAction, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pRemoveParkedOrderAction = pRemoveParkedOrderAction;
		}
	};

	/// <summary>
	/// 执行宣告录入请求响应事件参数
	/// </summary>
	public ref class RspExecOrderInsertArgs : BasicArgs
	{
	public:
		InputExecOrderField^ pInputExecOrder;

		/// <summary>
		/// 执行宣告录入请求响应事件参数
		/// </summary>
		/// <param name="pInputExecOrder">输入的执行宣告</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspExecOrderInsertArgs(InputExecOrderField^ pInputExecOrder, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pInputExecOrder = pInputExecOrder;
		}
	};

	/// <summary>
	/// 执行宣告操作请求响应事件参数
	/// </summary>
	public ref class RspExecOrderActionArgs : BasicArgs
	{
	public:
		InputExecOrderActionField^ pInputExecOrderAction;

		/// <summary>
		/// 执行宣告操作请求响应事件参数
		/// </summary>
		/// <param name="pInputExecOrderAction">输入执行宣告操作</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspExecOrderActionArgs(InputExecOrderActionField^ pInputExecOrderAction, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pInputExecOrderAction = pInputExecOrderAction;
		}
	};

	/// <summary>
	/// 询价录入请求响应事件参数
	/// </summary>
	public ref class RspForQuoteInsertArgs : BasicArgs
	{
	public:
		InputForQuoteField^ pInputForQuote;

		/// <summary>
		/// 询价录入请求响应事件参数
		/// </summary>
		/// <param name="pInputForQuote">输入的询价</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspForQuoteInsertArgs(InputForQuoteField^ pInputForQuote, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pInputForQuote = pInputForQuote;
		}
	};

	/// <summary>
	/// 报价录入请求响应事件参数
	/// </summary>
	public ref class RspQuoteInsertArgs : BasicArgs
	{
	public:
		InputQuoteField^ pInputQuote;

		/// <summary>
		/// 报价录入请求响应事件参数
		/// </summary>
		/// <param name="pInputQuote">输入的报价</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQuoteInsertArgs(InputQuoteField^ pInputQuote, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pInputQuote = pInputQuote;
		}
	};

	/// <summary>
	/// 报价操作请求响应事件参数
	/// </summary>
	public ref class RspQuoteActionArgs : BasicArgs
	{
	public:
		InputQuoteActionField^ pInputQuoteAction;

		/// <summary>
		/// 报价操作请求响应事件参数
		/// </summary>
		/// <param name="pInputQuoteAction">输入报价操作</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQuoteActionArgs(InputQuoteActionField^ pInputQuoteAction, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pInputQuoteAction = pInputQuoteAction;
		}
	};

	/// <summary>
	/// 批量报单操作请求响应事件参数
	/// </summary>
	public ref class RspBatchOrderActionArgs : BasicArgs
	{
	public:
		InputBatchOrderActionField^ pInputBatchOrderAction;

		/// <summary>
		/// 批量报单操作请求响应事件参数
		/// </summary>
		/// <param name="pInputBatchOrderAction">输入批量报单操作</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspBatchOrderActionArgs(InputBatchOrderActionField^ pInputBatchOrderAction, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pInputBatchOrderAction = pInputBatchOrderAction;
		}
	};

	/// <summary>
	/// 期权自对冲录入请求响应事件参数
	/// </summary>
	public ref class RspOptionSelfCloseInsertArgs : BasicArgs
	{
	public:
		InputOptionSelfCloseField^ pInputOptionSelfClose;

		/// <summary>
		/// 期权自对冲录入请求响应事件参数
		/// </summary>
		/// <param name="pInputOptionSelfClose">输入的期权自对冲</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspOptionSelfCloseInsertArgs(InputOptionSelfCloseField^ pInputOptionSelfClose, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pInputOptionSelfClose = pInputOptionSelfClose;
		}
	};

	/// <summary>
	/// 期权自对冲操作请求响应事件参数
	/// </summary>
	public ref class RspOptionSelfCloseActionArgs : BasicArgs
	{
	public:
		InputOptionSelfCloseActionField^ pInputOptionSelfCloseAction;

		/// <summary>
		/// 期权自对冲操作请求响应事件参数
		/// </summary>
		/// <param name="pInputOptionSelfCloseAction">输入期权自对冲操作</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspOptionSelfCloseActionArgs(InputOptionSelfCloseActionField^ pInputOptionSelfCloseAction, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pInputOptionSelfCloseAction = pInputOptionSelfCloseAction;
		}
	};

	/// <summary>
	/// 申请组合录入请求响应事件参数
	/// </summary>
	public ref class RspCombActionInsertArgs : BasicArgs
	{
	public:
		InputCombActionField^ pInputCombAction;

		/// <summary>
		/// 申请组合录入请求响应事件参数
		/// </summary>
		/// <param name="pInputCombAction">输入的申请组合</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspCombActionInsertArgs(InputCombActionField^ pInputCombAction, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pInputCombAction = pInputCombAction;
		}
	};

	/// <summary>
	/// 请求查询报单响应事件参数
	/// </summary>
	public ref class RspQryOrderArgs : BasicArgs
	{
	public:
		OrderField^ pOrder;

		/// <summary>
		/// 请求查询报单响应事件参数
		/// </summary>
		/// <param name="pOrder">报单</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQryOrderArgs(OrderField^ pOrder, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pOrder = pOrder;
		}
	};

	/// <summary>
	/// 请求查询成交响应事件参数
	/// </summary>
	public ref class RspQryTradeArgs : BasicArgs
	{
	public:
		TradeField^ pTrade;

		/// <summary>
		/// 请求查询成交响应事件参数
		/// </summary>
		/// <param name="pTrade">成交</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQryTradeArgs(TradeField^ pTrade, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pTrade = pTrade;
		}
	};

	/// <summary>
	/// 请求查询投资者持仓响应事件参数
	/// </summary>
	public ref class RspQryInvestorPositionArgs : BasicArgs
	{
	public:
		InvestorPositionField^ pInvestorPosition;

		/// <summary>
		/// 请求查询投资者持仓响应事件参数
		/// </summary>
		/// <param name="pInvestorPosition">投资者持仓</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQryInvestorPositionArgs(InvestorPositionField^ pInvestorPosition, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pInvestorPosition = pInvestorPosition;
		}
	};

	/// <summary>
	/// 请求查询资金账户响应事件参数
	/// </summary>
	public ref class RspQryTradingAccountArgs : BasicArgs
	{
	public:
		TradingAccountField^ pTradingAccount;

		/// <summary>
		/// 请求查询资金账户响应事件参数
		/// </summary>
		/// <param name="pTradingAccount">资金账户</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQryTradingAccountArgs(TradingAccountField^ pTradingAccount, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pTradingAccount = pTradingAccount;
		}
	};

	/// <summary>
	/// 请求查询投资者响应事件参数
	/// </summary>
	public ref class RspQryInvestorArgs : BasicArgs
	{
	public:
		InvestorField^ pInvestor;

		/// <summary>
		/// 请求查询投资者响应事件参数
		/// </summary>
		/// <param name="pInvestor">投资者</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQryInvestorArgs(InvestorField^ pInvestor, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pInvestor = pInvestor;
		}
	};

	/// <summary>
	/// 请求查询交易编码响应事件参数
	/// </summary>
	public ref class RspQryTradingCodeArgs : BasicArgs
	{
	public:
		TradingCodeField^ pTradingCode;

		/// <summary>
		/// 请求查询交易编码响应事件参数
		/// </summary>
		/// <param name="pTradingCode">交易编码</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQryTradingCodeArgs(TradingCodeField^ pTradingCode, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pTradingCode = pTradingCode;
		}
	};

	/// <summary>
	/// 请求查询合约保证金率响应事件参数
	/// </summary>
	public ref class RspQryInstrumentMarginRateArgs : BasicArgs
	{
	public:
		InstrumentMarginRateField^ pInstrumentMarginRate;

		/// <summary>
		/// 请求查询合约保证金率响应事件参数
		/// </summary>
		/// <param name="pInstrumentMarginRate">合约保证金率</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQryInstrumentMarginRateArgs(InstrumentMarginRateField^ pInstrumentMarginRate, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pInstrumentMarginRate = pInstrumentMarginRate;
		}
	};

	/// <summary>
	/// 请求查询合约手续费率响应事件参数
	/// </summary>
	public ref class RspQryInstrumentCommissionRateArgs : BasicArgs
	{
	public:
		InstrumentCommissionRateField^ pInstrumentCommissionRate;

		/// <summary>
		/// 请求查询合约手续费率响应事件参数
		/// </summary>
		/// <param name="pInstrumentCommissionRate">合约手续费率</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQryInstrumentCommissionRateArgs(InstrumentCommissionRateField^ pInstrumentCommissionRate, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pInstrumentCommissionRate = pInstrumentCommissionRate;
		}
	};

	/// <summary>
	/// 请求查询交易所响应事件参数
	/// </summary>
	public ref class RspQryExchangeArgs : BasicArgs
	{
	public:
		ExchangeField^ pExchange;

		/// <summary>
		/// 请求查询交易所响应事件参数
		/// </summary>
		/// <param name="pExchange">交易所</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQryExchangeArgs(ExchangeField^ pExchange, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pExchange = pExchange;
		}
	};

	/// <summary>
	/// 请求查询产品响应事件参数
	/// </summary>
	public ref class RspQryProductArgs : BasicArgs
	{
	public:
		ProductField^ pProduct;

		/// <summary>
		/// 请求查询产品响应事件参数
		/// </summary>
		/// <param name="pProduct">产品</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQryProductArgs(ProductField^ pProduct, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pProduct = pProduct;
		}
	};

	/// <summary>
	/// 请求查询合约响应事件参数
	/// </summary>
	public ref class RspQryInstrumentArgs : BasicArgs
	{
	public:
		InstrumentField^ pInstrument;

		/// <summary>
		/// 请求查询合约响应事件参数
		/// </summary>
		/// <param name="pInstrument">合约</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQryInstrumentArgs(InstrumentField^ pInstrument, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pInstrument = pInstrument;
		}
	};

	/// <summary>
	/// 请求查询行情响应事件参数
	/// </summary>
	public ref class RspQryDepthMarketDataArgs : BasicArgs
	{
	public:
		DepthMarketDataField^ pDepthMarketData;

		/// <summary>
		/// 请求查询行情响应事件参数
		/// </summary>
		/// <param name="pDepthMarketData">深度行情</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQryDepthMarketDataArgs(DepthMarketDataField^ pDepthMarketData, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pDepthMarketData = pDepthMarketData;
		}
	};

	/// <summary>
	/// 请求查询投资者结算结果响应事件参数
	/// </summary>
	public ref class RspQrySettlementInfoArgs : BasicArgs
	{
	public:
		SettlementInfoField^ pSettlementInfo;

		/// <summary>
		/// 请求查询投资者结算结果响应事件参数
		/// </summary>
		/// <param name="pSettlementInfo">投资者结算结果</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQrySettlementInfoArgs(SettlementInfoField^ pSettlementInfo, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pSettlementInfo = pSettlementInfo;
		}
	};

	/// <summary>
	/// 请求查询转帐银行响应事件参数
	/// </summary>
	public ref class RspQryTransferBankArgs : BasicArgs
	{
	public:
		TransferBankField^ pTransferBank;

		/// <summary>
		/// 请求查询转帐银行响应事件参数
		/// </summary>
		/// <param name="pTransferBank">转帐银行</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQryTransferBankArgs(TransferBankField^ pTransferBank, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pTransferBank = pTransferBank;
		}
	};

	/// <summary>
	/// 请求查询投资者持仓明细响应事件参数
	/// </summary>
	public ref class RspQryInvestorPositionDetailArgs : BasicArgs
	{
	public:
		InvestorPositionDetailField^ pInvestorPositionDetail;

		/// <summary>
		/// 请求查询投资者持仓明细响应事件参数
		/// </summary>
		/// <param name="pInvestorPositionDetail">投资者持仓明细</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQryInvestorPositionDetailArgs(InvestorPositionDetailField^ pInvestorPositionDetail, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pInvestorPositionDetail = pInvestorPositionDetail;
		}
	};

	/// <summary>
	/// 请求查询客户通知响应事件参数
	/// </summary>
	public ref class RspQryNoticeArgs : BasicArgs
	{
	public:
		NoticeField^ pNotice;

		/// <summary>
		/// 请求查询客户通知响应事件参数
		/// </summary>
		/// <param name="pNotice">客户通知</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQryNoticeArgs(NoticeField^ pNotice, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pNotice = pNotice;
		}
	};

	/// <summary>
	/// 请求查询结算信息确认响应事件参数
	/// </summary>
	public ref class RspQrySettlementInfoConfirmArgs : BasicArgs
	{
	public:
		SettlementInfoConfirmField^ pSettlementInfoConfirm;

		/// <summary>
		/// 请求查询结算信息确认响应事件参数
		/// </summary>
		/// <param name="pSettlementInfoConfirm">投资者结算结果确认信息</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQrySettlementInfoConfirmArgs(SettlementInfoConfirmField^ pSettlementInfoConfirm, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pSettlementInfoConfirm = pSettlementInfoConfirm;
		}
	};

	/// <summary>
	/// 请求查询投资者持仓明细响应事件参数
	/// </summary>
	public ref class RspQryInvestorPositionCombineDetailArgs : BasicArgs
	{
	public:
		InvestorPositionCombineDetailField^ pInvestorPositionCombineDetail;

		/// <summary>
		/// 请求查询投资者持仓明细响应事件参数
		/// </summary>
		/// <param name="pInvestorPositionCombineDetail">投资者组合持仓明细</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQryInvestorPositionCombineDetailArgs(InvestorPositionCombineDetailField^ pInvestorPositionCombineDetail, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pInvestorPositionCombineDetail = pInvestorPositionCombineDetail;
		}
	};

	/// <summary>
	/// 查询保证金监管系统经纪公司资金账户密钥响应事件参数
	/// </summary>
	public ref class RspQryCFMMCTradingAccountKeyArgs : BasicArgs
	{
	public:
		CFMMCTradingAccountKeyField^ pCFMMCTradingAccountKey;

		/// <summary>
		/// 查询保证金监管系统经纪公司资金账户密钥响应事件参数
		/// </summary>
		/// <param name="pCFMMCTradingAccountKey">保证金监管系统经纪公司资金账户密钥</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQryCFMMCTradingAccountKeyArgs(CFMMCTradingAccountKeyField^ pCFMMCTradingAccountKey, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pCFMMCTradingAccountKey = pCFMMCTradingAccountKey;
		}
	};

	/// <summary>
	/// 请求查询仓单折抵信息响应事件参数
	/// </summary>
	public ref class RspQryEWarrantOffsetArgs : BasicArgs
	{
	public:
		EWarrantOffsetField^ pEWarrantOffset;

		/// <summary>
		/// 请求查询仓单折抵信息响应事件参数
		/// </summary>
		/// <param name="pEWarrantOffset">仓单折抵信息</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQryEWarrantOffsetArgs(EWarrantOffsetField^ pEWarrantOffset, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pEWarrantOffset = pEWarrantOffset;
		}
	};

	/// <summary>
	/// 请求查询投资者品种跨品种保证金响应事件参数
	/// </summary>
	public ref class RspQryInvestorProductGroupMarginArgs : BasicArgs
	{
	public:
		InvestorProductGroupMarginField^ pInvestorProductGroupMargin;

		/// <summary>
		/// 请求查询投资者品种跨品种保证金响应事件参数
		/// </summary>
		/// <param name="pInvestorProductGroupMargin">投资者品种跨品种保证金</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQryInvestorProductGroupMarginArgs(InvestorProductGroupMarginField^ pInvestorProductGroupMargin, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pInvestorProductGroupMargin = pInvestorProductGroupMargin;
		}
	};

	/// <summary>
	/// 请求查询交易所保证金率响应事件参数
	/// </summary>
	public ref class RspQryExchangeMarginRateArgs : BasicArgs
	{
	public:
		ExchangeMarginRateField^ pExchangeMarginRate;

		/// <summary>
		/// 请求查询交易所保证金率响应事件参数
		/// </summary>
		/// <param name="pExchangeMarginRate">交易所保证金率</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQryExchangeMarginRateArgs(ExchangeMarginRateField^ pExchangeMarginRate, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pExchangeMarginRate = pExchangeMarginRate;
		}
	};

	/// <summary>
	/// 请求查询交易所调整保证金率响应事件参数
	/// </summary>
	public ref class RspQryExchangeMarginRateAdjustArgs : BasicArgs
	{
	public:
		ExchangeMarginRateAdjustField^ pExchangeMarginRateAdjust;

		/// <summary>
		/// 请求查询交易所调整保证金率响应事件参数
		/// </summary>
		/// <param name="pExchangeMarginRateAdjust">交易所保证金率调整</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQryExchangeMarginRateAdjustArgs(ExchangeMarginRateAdjustField^ pExchangeMarginRateAdjust, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pExchangeMarginRateAdjust = pExchangeMarginRateAdjust;
		}
	};

	/// <summary>
	/// 请求查询汇率响应事件参数
	/// </summary>
	public ref class RspQryExchangeRateArgs : BasicArgs
	{
	public:
		ExchangeRateField^ pExchangeRate;

		/// <summary>
		/// 请求查询汇率响应事件参数
		/// </summary>
		/// <param name="pExchangeRate">汇率</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQryExchangeRateArgs(ExchangeRateField^ pExchangeRate, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pExchangeRate = pExchangeRate;
		}
	};

	/// <summary>
	/// 请求查询二级代理操作员银期权限响应事件参数
	/// </summary>
	public ref class RspQrySecAgentACIDMapArgs : BasicArgs
	{
	public:
		SecAgentACIDMapField^ pSecAgentACIDMap;

		/// <summary>
		/// 请求查询二级代理操作员银期权限响应事件参数
		/// </summary>
		/// <param name="pSecAgentACIDMap">二级代理操作员银期权限</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQrySecAgentACIDMapArgs(SecAgentACIDMapField^ pSecAgentACIDMap, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pSecAgentACIDMap = pSecAgentACIDMap;
		}
	};

	/// <summary>
	/// 请求查询产品报价汇率事件参数
	/// </summary>
	public ref class RspQryProductExchRateArgs : BasicArgs
	{
	public:
		ProductExchRateField^ pProductExchRate;

		/// <summary>
		/// 请求查询产品报价汇率事件参数
		/// </summary>
		/// <param name="pProductExchRate">产品报价汇率</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQryProductExchRateArgs(ProductExchRateField^ pProductExchRate, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pProductExchRate = pProductExchRate;
		}
	};

	/// <summary>
	/// 请求查询产品组事件参数
	/// </summary>
	public ref class RspQryProductGroupArgs : BasicArgs
	{
	public:
		ProductGroupField^ pProductGroup;

		/// <summary>
		/// 请求查询产品组事件参数
		/// </summary>
		/// <param name="pProductGroup">投资者品种跨品种保证金产品组</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQryProductGroupArgs(ProductGroupField^ pProductGroup, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pProductGroup = pProductGroup;
		}
	};

	/// <summary>
	/// 请求查询做市商合约手续费率响应事件参数
	/// </summary>
	public ref class RspQryMMInstrumentCommissionRateArgs : BasicArgs
	{
	public:
		MMInstrumentCommissionRateField^ pMMInstrumentCommissionRate;

		/// <summary>
		/// 请求查询做市商合约手续费率响应事件参数
		/// </summary>
		/// <param name="pMMInstrumentCommissionRate">做市商合约手续费率</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQryMMInstrumentCommissionRateArgs(MMInstrumentCommissionRateField^ pMMInstrumentCommissionRate, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pMMInstrumentCommissionRate = pMMInstrumentCommissionRate;
		}
	};

	/// <summary>
	/// 请求查询做市商期权合约手续费响应事件参数
	/// </summary>
	public ref class RspQryMMOptionInstrCommRateArgs : BasicArgs
	{
	public:
		MMOptionInstrCommRateField^ pMMOptionInstrCommRate;

		/// <summary>
		/// 请求查询做市商期权合约手续费响应事件参数
		/// </summary>
		/// <param name="pMMOptionInstrCommRate">当前做市商期权合约手续费的详细内容</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQryMMOptionInstrCommRateArgs(MMOptionInstrCommRateField^ pMMOptionInstrCommRate, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pMMOptionInstrCommRate = pMMOptionInstrCommRate;
		}
	};

	/// <summary>
	/// 请求查询报单手续费响应事件参数
	/// </summary>
	public ref class RspQryInstrumentOrderCommRateArgs : BasicArgs
	{
	public:
		InstrumentOrderCommRateField^ pInstrumentOrderCommRate;

		/// <summary>
		/// 请求查询报单手续费响应事件参数
		/// </summary>
		/// <param name="pInstrumentOrderCommRate">当前报单手续费的详细内容</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQryInstrumentOrderCommRateArgs(InstrumentOrderCommRateField^ pInstrumentOrderCommRate, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pInstrumentOrderCommRate = pInstrumentOrderCommRate;
		}
	};

	/// <summary>
	/// 请求查询资金账户响应事件参数
	/// </summary>
	public ref class RspQrySecAgentTradingAccountArgs : BasicArgs
	{
	public:
		TradingAccountField^ pTradingAccount;

		/// <summary>
		/// 请求查询资金账户响应事件参数
		/// </summary>
		/// <param name="pTradingAccount">资金账户</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQrySecAgentTradingAccountArgs(TradingAccountField^ pTradingAccount, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pTradingAccount = pTradingAccount;
		}
	};

	/// <summary>
	/// 请求查询二级代理商资金校验模式响应事件参数
	/// </summary>
	public ref class RspQrySecAgentCheckModeArgs : BasicArgs
	{
	public:
		SecAgentCheckModeField^ pSecAgentCheckMode;

		/// <summary>
		/// 请求查询二级代理商资金校验模式响应事件参数
		/// </summary>
		/// <param name="pSecAgentCheckMode">二级代理商资金校验模式</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQrySecAgentCheckModeArgs(SecAgentCheckModeField^ pSecAgentCheckMode, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pSecAgentCheckMode = pSecAgentCheckMode;
		}
	};

	/// <summary>
	/// 请求查询二级代理商信息响应事件参数
	/// </summary>
	public ref class RspQrySecAgentTradeInfoArgs : BasicArgs
	{
	public:
		SecAgentTradeInfoField^ pSecAgentTradeInfo;

		/// <summary>
		/// 请求查询二级代理商信息响应事件参数
		/// </summary>
		/// <param name="pSecAgentTradeInfo">二级代理商信息</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQrySecAgentTradeInfoArgs(SecAgentTradeInfoField^ pSecAgentTradeInfo, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pSecAgentTradeInfo = pSecAgentTradeInfo;
		}
	};

	/// <summary>
	/// 请求查询期权交易成本响应事件参数
	/// </summary>
	public ref class RspQryOptionInstrTradeCostArgs : BasicArgs
	{
	public:
		OptionInstrTradeCostField^ pOptionInstrTradeCost;

		/// <summary>
		/// 请求查询期权交易成本响应事件参数
		/// </summary>
		/// <param name="pOptionInstrTradeCost">期权交易成本</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQryOptionInstrTradeCostArgs(OptionInstrTradeCostField^ pOptionInstrTradeCost, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pOptionInstrTradeCost = pOptionInstrTradeCost;
		}
	};

	/// <summary>
	/// 请求查询期权合约手续费响应事件参数
	/// </summary>
	public ref class RspQryOptionInstrCommRateArgs : BasicArgs
	{
	public:
		OptionInstrCommRateField^ pOptionInstrCommRate;

		/// <summary>
		/// 请求查询期权合约手续费响应事件参数
		/// </summary>
		/// <param name="pOptionInstrCommRate">当前期权合约手续费的详细内容</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQryOptionInstrCommRateArgs(OptionInstrCommRateField^ pOptionInstrCommRate, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pOptionInstrCommRate = pOptionInstrCommRate;
		}
	};

	/// <summary>
	/// 请求查询执行宣告响应事件参数
	/// </summary>
	public ref class RspQryExecOrderArgs : BasicArgs
	{
	public:
		ExecOrderField^ pExecOrder;

		/// <summary>
		/// 请求查询执行宣告响应事件参数
		/// </summary>
		/// <param name="pExecOrder">执行宣告</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQryExecOrderArgs(ExecOrderField^ pExecOrder, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pExecOrder = pExecOrder;
		}
	};

	/// <summary>
	/// 请求查询询价响应事件参数
	/// </summary>
	public ref class RspQryForQuoteArgs : BasicArgs
	{
	public:
		ForQuoteField^ pForQuote;

		/// <summary>
		/// 请求查询询价响应事件参数
		/// </summary>
		/// <param name="pForQuote">询价</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQryForQuoteArgs(ForQuoteField^ pForQuote, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pForQuote = pForQuote;
		}
	};

	/// <summary>
	/// 请求查询报价响应事件参数
	/// </summary>
	public ref class RspQryQuoteArgs : BasicArgs
	{
	public:
		QuoteField^ pQuote;

		/// <summary>
		/// 请求查询报价响应事件参数
		/// </summary>
		/// <param name="pQuote">报价</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQryQuoteArgs(QuoteField^ pQuote, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pQuote = pQuote;
		}
	};

	/// <summary>
	/// 请求查询期权自对冲响应事件参数
	/// </summary>
	public ref class RspQryOptionSelfCloseArgs : BasicArgs
	{
	public:
		OptionSelfCloseField^ pOptionSelfClose;

		/// <summary>
		/// 请求查询期权自对冲响应事件参数
		/// </summary>
		/// <param name="pOptionSelfClose">期权自对冲</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQryOptionSelfCloseArgs(OptionSelfCloseField^ pOptionSelfClose, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pOptionSelfClose = pOptionSelfClose;
		}
	};

	/// <summary>
	/// 请求查询投资单元响应事件参数
	/// </summary>
	public ref class RspQryInvestUnitArgs : BasicArgs
	{
	public:
		InvestUnitField^ pInvestUnit;

		/// <summary>
		/// 请求查询投资单元响应事件参数
		/// </summary>
		/// <param name="pInvestUnit">投资单元</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQryInvestUnitArgs(InvestUnitField^ pInvestUnit, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pInvestUnit = pInvestUnit;
		}
	};

	/// <summary>
	/// 请求查询组合合约安全系数响应事件参数
	/// </summary>
	public ref class RspQryCombInstrumentGuardArgs : BasicArgs
	{
	public:
		CombInstrumentGuardField^ pCombInstrumentGuard;

		/// <summary>
		/// 请求查询组合合约安全系数响应事件参数
		/// </summary>
		/// <param name="pCombInstrumentGuard">组合合约安全系数</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQryCombInstrumentGuardArgs(CombInstrumentGuardField^ pCombInstrumentGuard, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pCombInstrumentGuard = pCombInstrumentGuard;
		}
	};

	/// <summary>
	/// 请求查询申请组合响应事件参数
	/// </summary>
	public ref class RspQryCombActionArgs : BasicArgs
	{
	public:
		CombActionField^ pCombAction;

		/// <summary>
		/// 请求查询申请组合响应事件参数
		/// </summary>
		/// <param name="pCombAction">申请组合</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQryCombActionArgs(CombActionField^ pCombAction, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pCombAction = pCombAction;
		}
	};

	/// <summary>
	/// 请求查询转帐流水响应事件参数
	/// </summary>
	public ref class RspQryTransferSerialArgs : BasicArgs
	{
	public:
		TransferSerialField^ pTransferSerial;

		/// <summary>
		/// 请求查询转帐流水响应事件参数
		/// </summary>
		/// <param name="pTransferSerial">银期转账交易流水表</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQryTransferSerialArgs(TransferSerialField^ pTransferSerial, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pTransferSerial = pTransferSerial;
		}
	};

	/// <summary>
	/// 请求查询银期签约关系响应事件参数
	/// </summary>
	public ref class RspQryAccountregisterArgs : BasicArgs
	{
	public:
		AccountregisterField^ pAccountregister;

		/// <summary>
		/// 请求查询银期签约关系响应事件参数
		/// </summary>
		/// <param name="pAccountregister">客户开销户信息表</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQryAccountregisterArgs(AccountregisterField^ pAccountregister, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pAccountregister = pAccountregister;
		}
	};



	/// <summary>
	/// 报单通知事件参数
	/// </summary>
	public ref class RtnOrderArgs : System::EventArgs
	{
	public:
		OrderField^ pOrder;

		/// <summary>
		/// 报单通知事件参数
		/// </summary>
		/// <param name="pOrder">报单</param>
		RtnOrderArgs(OrderField^ pOrder)
		{
			this->pOrder = pOrder;
		}
	};

	/// <summary>
	/// 成交通知事件参数
	/// </summary>
	public ref class RtnTradeArgs : System::EventArgs
	{
	public:
		TradeField^ pTrade;

		/// <summary>
		/// 成交通知事件参数
		/// </summary>
		/// <param name="pTrade">成交</param>
		RtnTradeArgs(TradeField^ pTrade)
		{
			this->pTrade = pTrade;
		}
	};

	/// <summary>
	/// 报单录入错误回报事件参数
	/// </summary>
	public ref class ErrRtnOrderInsertArgs : System::EventArgs
	{
	public:
		InputOrderField^ pInputOrder;
		RspInfoField^ pRspInfo;

		/// <summary>
		/// 报单录入错误回报事件参数
		/// </summary>
		/// <param name="pInputOrder">输入报单</param>
		/// <param name="pRspInfo">响应信息</param>
		ErrRtnOrderInsertArgs(InputOrderField^ pInputOrder, RspInfoField^ pRspInfo)
		{
			this->pInputOrder = pInputOrder;
		}
	};

	/// <summary>
	/// 报单操作错误回报事件参数
	/// </summary>
	public ref class ErrRtnOrderActionArgs : System::EventArgs
	{
	public:
		OrderActionField^ pOrderAction;
		RspInfoField^ pRspInfo;

		/// <summary>
		/// 报单操作错误回报事件参数
		/// </summary>
		/// <param name="pOrderAction">报单操作</param>
		/// <param name="pRspInfo">响应信息</param>
		ErrRtnOrderActionArgs(OrderActionField^ pOrderAction, RspInfoField^ pRspInfo)
		{
			this->pOrderAction = pOrderAction;
		}
	};

	/// <summary>
	/// 合约交易状态通知事件参数
	/// </summary>
	public ref class RtnInstrumentStatusArgs : System::EventArgs
	{
	public:
		InstrumentStatusField^ pInstrumentStatus;

		/// <summary>
		/// 合约交易状态通知事件参数
		/// </summary>
		/// <param name="pInstrumentStatus">合约状态</param>
		RtnInstrumentStatusArgs(InstrumentStatusField^ pInstrumentStatus)
		{
			this->pInstrumentStatus = pInstrumentStatus;
		}
	};

	/// <summary>
	/// 交易所公告通知事件参数
	/// </summary>
	public ref class RtnBulletinArgs : System::EventArgs
	{
	public:
		BulletinField^ pBulletin;

		/// <summary>
		/// 交易所公告通知事件参数
		/// </summary>
		/// <param name="pBulletin">交易所公告</param>
		RtnBulletinArgs(BulletinField^ pBulletin)
		{
			this->pBulletin = pBulletin;
		}
	};

	/// <summary>
	/// 交易通知事件参数
	/// </summary>
	public ref class RtnTradingNoticeArgs : System::EventArgs
	{
	public:
		TradingNoticeInfoField^ pTradingNoticeInfo;

		/// <summary>
		/// 交易通知事件参数
		/// </summary>
		/// <param name="pTradingNoticeInfo">用户事件通知信息</param>
		RtnTradingNoticeArgs(TradingNoticeInfoField^ pTradingNoticeInfo)
		{
			this->pTradingNoticeInfo = pTradingNoticeInfo;
		}
	};

	/// <summary>
	/// 提示条件单校验错误事件参数
	/// </summary>
	public ref class RtnErrorConditionalOrderArgs : System::EventArgs
	{
	public:
		ErrorConditionalOrderField^ pErrorConditionalOrder;

		/// <summary>
		/// 提示条件单校验错误事件参数
		/// </summary>
		/// <param name="pErrorConditionalOrder">查询错误报单操作</param>
		RtnErrorConditionalOrderArgs(ErrorConditionalOrderField^ pErrorConditionalOrder)
		{
			this->pErrorConditionalOrder = pErrorConditionalOrder;
		}
	};

	/// <summary>
	/// 执行宣告通知事件参数
	/// </summary>
	public ref class RtnExecOrderArgs : System::EventArgs
	{
	public:
		ExecOrderField^ pExecOrder;

		/// <summary>
		/// 执行宣告通知事件参数
		/// </summary>
		/// <param name="pExecOrder">执行宣告</param>
		RtnExecOrderArgs(ExecOrderField^ pExecOrder)
		{
			this->pExecOrder = pExecOrder;
		}
	};

	/// <summary>
	/// 执行宣告录入错误回报事件参数
	/// </summary>
	public ref class ErrRtnExecOrderInsertArgs : System::EventArgs
	{
	public:
		InputExecOrderField^ pInputExecOrder;
		RspInfoField^ pRspInfo;

		/// <summary>
		/// 执行宣告录入错误回报事件参数
		/// </summary>
		/// <param name="pInputExecOrder">输入的执行宣告</param>
		/// <param name="pRspInfo">响应信息</param>
		ErrRtnExecOrderInsertArgs(InputExecOrderField^ pInputExecOrder, RspInfoField^ pRspInfo)
		{
			this->pInputExecOrder = pInputExecOrder;
		}
	};

	/// <summary>
	/// 执行宣告操作错误回报事件参数
	/// </summary>
	public ref class ErrRtnExecOrderActionArgs : System::EventArgs
	{
	public:
		ExecOrderActionField^ pExecOrderAction;
		RspInfoField^ pRspInfo;

		/// <summary>
		/// 执行宣告操作错误回报事件参数
		/// </summary>
		/// <param name="pExecOrderAction">执行宣告操作</param>
		/// <param name="pRspInfo">响应信息</param>
		ErrRtnExecOrderActionArgs(ExecOrderActionField^ pExecOrderAction, RspInfoField^ pRspInfo)
		{
			this->pExecOrderAction = pExecOrderAction;
		}
	};

	/// <summary>
	/// 询价录入错误回报事件参数
	/// </summary>
	public ref class ErrRtnForQuoteInsertArgs : System::EventArgs
	{
	public:
		InputForQuoteField^ pInputForQuote;
		RspInfoField^ pRspInfo;

		/// <summary>
		/// 询价录入错误回报事件参数
		/// </summary>
		/// <param name="pInputForQuote">输入的询价</param>
		/// <param name="pRspInfo">响应信息</param>
		ErrRtnForQuoteInsertArgs(InputForQuoteField^ pInputForQuote, RspInfoField^ pRspInfo)
		{
			this->pInputForQuote = pInputForQuote;
		}
	};

	/// <summary>
	/// 报价通知事件参数
	/// </summary>
	public ref class RtnQuoteArgs : System::EventArgs
	{
	public:
		QuoteField^ pQuote;

		/// <summary>
		/// 报价通知事件参数
		/// </summary>
		/// <param name="pQuote">报价</param>
		RtnQuoteArgs(QuoteField^ pQuote)
		{
			this->pQuote = pQuote;
		}
	};

	/// <summary>
	/// 报价录入错误回报事件参数
	/// </summary>
	public ref class ErrRtnQuoteInsertArgs : System::EventArgs
	{
	public:
		InputQuoteField^ pInputQuote;
		RspInfoField^ pRspInfo;

		/// <summary>
		/// 报价录入错误回报事件参数
		/// </summary>
		/// <param name="pInputQuote">输入的报价</param>
		/// <param name="pRspInfo">响应信息</param>
		ErrRtnQuoteInsertArgs(InputQuoteField^ pInputQuote, RspInfoField^ pRspInfo)
		{
			this->pInputQuote = pInputQuote;
		}
	};

	/// <summary>
	/// 报价操作错误回报事件参数
	/// </summary>
	public ref class ErrRtnQuoteActionArgs : System::EventArgs
	{
	public:
		QuoteActionField^ pQuoteAction;
		RspInfoField^ pRspInfo;

		/// <summary>
		/// 报价操作错误回报事件参数
		/// </summary>
		/// <param name="pQuoteAction">报价操作</param>
		/// <param name="pRspInfo">响应信息</param>
		ErrRtnQuoteActionArgs(QuoteActionField^ pQuoteAction, RspInfoField^ pRspInfo)
		{
			this->pQuoteAction = pQuoteAction;
		}
	};

	/// <summary>
	/// 保证金监控中心用户令牌事件参数
	/// </summary>
	public ref class RtnCFMMCTradingAccountTokenArgs : System::EventArgs
	{
	public:
		CFMMCTradingAccountTokenField^ pCFMMCTradingAccountToken;

		/// <summary>
		/// 保证金监控中心用户令牌事件参数
		/// </summary>
		/// <param name="pCFMMCTradingAccountToken">监控中心用户令牌</param>
		RtnCFMMCTradingAccountTokenArgs(CFMMCTradingAccountTokenField^ pCFMMCTradingAccountToken)
		{
			this->pCFMMCTradingAccountToken = pCFMMCTradingAccountToken;
		}
	};

	/// <summary>
	/// 批量报单操作错误回报事件参数
	/// </summary>
	public ref class ErrRtnBatchOrderActionArgs : System::EventArgs
	{
	public:
		BatchOrderActionField^ pBatchOrderAction;
		RspInfoField^ pRspInfo;

		/// <summary>
		/// 批量报单操作错误回报事件参数
		/// </summary>
		/// <param name="pBatchOrderAction">批量报单操作</param>
		/// <param name="pRspInfo">响应信息</param>
		ErrRtnBatchOrderActionArgs(BatchOrderActionField^ pBatchOrderAction, RspInfoField^ pRspInfo)
		{
			this->pBatchOrderAction = pBatchOrderAction;
		}
	};

	/// <summary>
	/// 期权自对冲通知事件参数
	/// </summary>
	public ref class RtnOptionSelfCloseArgs : System::EventArgs
	{
	public:
		OptionSelfCloseField^ pOptionSelfClose;

		/// <summary>
		/// 期权自对冲通知事件参数
		/// </summary>
		/// <param name="pOptionSelfClose">期权自对冲</param>
		RtnOptionSelfCloseArgs(OptionSelfCloseField^ pOptionSelfClose)
		{
			this->pOptionSelfClose = pOptionSelfClose;
		}
	};

	/// <summary>
	/// 期权自对冲录入错误回报事件参数
	/// </summary>
	public ref class ErrRtnOptionSelfCloseInsertArgs : System::EventArgs
	{
	public:
		InputOptionSelfCloseField^ pInputOptionSelfClose;
		RspInfoField^ pRspInfo;

		/// <summary>
		/// 期权自对冲录入错误回报事件参数
		/// </summary>
		/// <param name="pInputOptionSelfClose">输入的期权自对冲</param>
		/// <param name="pRspInfo">响应信息</param>
		ErrRtnOptionSelfCloseInsertArgs(InputOptionSelfCloseField^ pInputOptionSelfClose, RspInfoField^ pRspInfo)
		{
			this->pInputOptionSelfClose = pInputOptionSelfClose;
		}
	};

	/// <summary>
	/// 期权自对冲操作错误回报事件参数
	/// </summary>
	public ref class ErrRtnOptionSelfCloseActionArgs : System::EventArgs
	{
	public:
		OptionSelfCloseActionField^ pOptionSelfCloseAction;
		RspInfoField^ pRspInfo;

		/// <summary>
		/// 期权自对冲操作错误回报事件参数
		/// </summary>
		/// <param name="pOptionSelfCloseAction">期权自对冲操作</param>
		/// <param name="pRspInfo">响应信息</param>
		ErrRtnOptionSelfCloseActionArgs(OptionSelfCloseActionField^ pOptionSelfCloseAction, RspInfoField^ pRspInfo)
		{
			this->pOptionSelfCloseAction = pOptionSelfCloseAction;
		}
	};

	/// <summary>
	/// 申请组合通知事件参数
	/// </summary>
	public ref class RtnCombActionArgs : System::EventArgs
	{
	public:
		CombActionField^ pCombAction;

		/// <summary>
		/// 申请组合通知事件参数
		/// </summary>
		/// <param name="pCombAction">申请组合</param>
		RtnCombActionArgs(CombActionField^ pCombAction)
		{
			this->pCombAction = pCombAction;
		}
	};

	/// <summary>
	/// 申请组合录入错误回报事件参数
	/// </summary>
	public ref class ErrRtnCombActionInsertArgs : System::EventArgs
	{
	public:
		InputCombActionField^ pInputCombAction;
		RspInfoField^ pRspInfo;

		/// <summary>
		/// 申请组合录入错误回报事件参数
		/// </summary>
		/// <param name="pInputCombAction">输入的申请组合</param>
		/// <param name="pRspInfo">响应信息</param>
		ErrRtnCombActionInsertArgs(InputCombActionField^ pInputCombAction, RspInfoField^ pRspInfo)
		{
			this->pInputCombAction = pInputCombAction;
		}
	};

	/// <summary>
	/// 请求查询签约银行响应事件参数
	/// </summary>
	public ref class RspQryContractBankArgs : BasicArgs
	{
	public:
		ContractBankField^ pContractBank;

		/// <summary>
		/// 请求查询签约银行响应事件参数
		/// </summary>
		/// <param name="pContractBank">查询签约银行响应</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQryContractBankArgs(ContractBankField^ pContractBank, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pContractBank = pContractBank;
		}
	};

	/// <summary>
	/// 请求查询预埋单响应事件参数
	/// </summary>
	public ref class RspQryParkedOrderArgs : BasicArgs
	{
	public:
		ParkedOrderField^ pParkedOrder;

		/// <summary>
		/// 请求查询预埋单响应事件参数
		/// </summary>
		/// <param name="pParkedOrder">预埋单</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQryParkedOrderArgs(ParkedOrderField^ pParkedOrder, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pParkedOrder = pParkedOrder;
		}
	};

	/// <summary>
	/// 请求查询预埋撤单响应事件参数
	/// </summary>
	public ref class RspQryParkedOrderActionArgs : BasicArgs
	{
	public:
		ParkedOrderActionField^ pParkedOrderAction;

		/// <summary>
		/// 请求查询预埋撤单响应事件参数
		/// </summary>
		/// <param name="pParkedOrderAction">输入预埋单操作</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQryParkedOrderActionArgs(ParkedOrderActionField^ pParkedOrderAction, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pParkedOrderAction = pParkedOrderAction;
		}
	};

	/// <summary>
	/// 请求查询交易通知响应事件参数
	/// </summary>
	public ref class RspQryTradingNoticeArgs : BasicArgs
	{
	public:
		TradingNoticeField^ pTradingNotice;

		/// <summary>
		/// 请求查询交易通知响应事件参数
		/// </summary>
		/// <param name="pTradingNotice">用户事件通知</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQryTradingNoticeArgs(TradingNoticeField^ pTradingNotice, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pTradingNotice = pTradingNotice;
		}
	};

	/// <summary>
	/// 请求查询经纪公司交易参数响应事件参数
	/// </summary>
	public ref class RspQryBrokerTradingParamsArgs : BasicArgs
	{
	public:
		BrokerTradingParamsField^ pBrokerTradingParams;

		/// <summary>
		/// 请求查询经纪公司交易参数响应事件参数
		/// </summary>
		/// <param name="pBrokerTradingParams">经纪公司交易参数</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQryBrokerTradingParamsArgs(BrokerTradingParamsField^ pBrokerTradingParams, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pBrokerTradingParams = pBrokerTradingParams;
		}
	};

	/// <summary>
	/// 请求查询经纪公司交易算法响应事件参数
	/// </summary>
	public ref class RspQryBrokerTradingAlgosArgs : BasicArgs
	{
	public:
		BrokerTradingAlgosField^ pBrokerTradingAlgos;

		/// <summary>
		/// 请求查询经纪公司交易算法响应事件参数
		/// </summary>
		/// <param name="pBrokerTradingAlgos">经纪公司交易算法</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQryBrokerTradingAlgosArgs(BrokerTradingAlgosField^ pBrokerTradingAlgos, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pBrokerTradingAlgos = pBrokerTradingAlgos;
		}
	};

	/// <summary>
	/// 请求查询监控中心用户令牌事件参数
	/// </summary>
	public ref class RspQueryCFMMCTradingAccountTokenArgs : BasicArgs
	{
	public:
		QueryCFMMCTradingAccountTokenField^ pQueryCFMMCTradingAccountToken;

		/// <summary>
		/// 请求查询监控中心用户令牌事件参数
		/// </summary>
		/// <param name="pQueryCFMMCTradingAccountToken">查询监控中心用户令牌</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQueryCFMMCTradingAccountTokenArgs(QueryCFMMCTradingAccountTokenField^ pQueryCFMMCTradingAccountToken, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pQueryCFMMCTradingAccountToken = pQueryCFMMCTradingAccountToken;
		}
	};

	/// <summary>
	/// 银行发起银行资金转期货通知事件参数
	/// </summary>
	public ref class RtnFromBankToFutureByBankArgs : System::EventArgs
	{
	public:
		RspTransferField^ pRspTransfer;

		/// <summary>
		/// 银行发起银行资金转期货通知事件参数
		/// </summary>
		/// <param name="pRspTransfer">银行发起银行资金转期货响应</param>
		RtnFromBankToFutureByBankArgs(RspTransferField^ pRspTransfer)
		{
			this->pRspTransfer = pRspTransfer;
		}
	};

	/// <summary>
	/// 银行发起期货资金转银行通知事件参数
	/// </summary>
	public ref class RtnFromFutureToBankByBankArgs : System::EventArgs
	{
	public:
		RspTransferField^ pRspTransfer;

		/// <summary>
		/// 银行发起期货资金转银行通知事件参数
		/// </summary>
		/// <param name="pRspTransfer">银行发起银行资金转期货响应</param>
		RtnFromFutureToBankByBankArgs(RspTransferField^ pRspTransfer)
		{
			this->pRspTransfer = pRspTransfer;
		}
	};

	/// <summary>
	/// 银行发起冲正银行转期货通知事件参数
	/// </summary>
	public ref class RtnRepealFromBankToFutureByBankArgs : System::EventArgs
	{
	public:
		RspRepealField^ pRspRepeal;

		/// <summary>
		/// 银行发起冲正银行转期货通知事件参数
		/// </summary>
		/// <param name="pRspRepeal">冲正响应</param>
		RtnRepealFromBankToFutureByBankArgs(RspRepealField^ pRspRepeal)
		{
			this->pRspRepeal = pRspRepeal;
		}
	};

	/// <summary>
	/// 银行发起冲正期货转银行通知事件参数
	/// </summary>
	public ref class RtnRepealFromFutureToBankByBankArgs : System::EventArgs
	{
	public:
		RspRepealField^ pRspRepeal;

		/// <summary>
		/// 银行发起冲正期货转银行通知事件参数
		/// </summary>
		/// <param name="pRspRepeal">冲正响应</param>
		RtnRepealFromFutureToBankByBankArgs(RspRepealField^ pRspRepeal)
		{
			this->pRspRepeal = pRspRepeal;
		}
	};

	/// <summary>
	/// 期货发起银行资金转期货通知事件参数
	/// </summary>
	public ref class RtnFromBankToFutureByFutureArgs : System::EventArgs
	{
	public:
		RspTransferField^ pRspTransfer;

		/// <summary>
		/// 期货发起银行资金转期货通知事件参数
		/// </summary>
		/// <param name="pRspTransfer">银行发起银行资金转期货响应</param>
		RtnFromBankToFutureByFutureArgs(RspTransferField^ pRspTransfer)
		{
			this->pRspTransfer = pRspTransfer;
		}
	};

	/// <summary>
	/// 期货发起期货资金转银行通知事件参数
	/// </summary>
	public ref class RtnFromFutureToBankByFutureArgs : System::EventArgs
	{
	public:
		RspTransferField^ pRspTransfer;

		/// <summary>
		/// 期货发起期货资金转银行通知事件参数
		/// </summary>
		/// <param name="pRspTransfer">银行发起银行资金转期货响应</param>
		RtnFromFutureToBankByFutureArgs(RspTransferField^ pRspTransfer)
		{
			this->pRspTransfer = pRspTransfer;
		}
	};

	/// <summary>
	/// 系统运行时期货端手工发起冲正银行转期货请求，银行处理完毕后报盘发回的通知事件参数
	/// </summary>
	public ref class RtnRepealFromBankToFutureByFutureManualArgs : System::EventArgs
	{
	public:
		RspRepealField^ pRspRepeal;

		/// <summary>
		/// 系统运行时期货端手工发起冲正银行转期货请求，银行处理完毕后报盘发回的通知事件参数
		/// </summary>
		/// <param name="pRspRepeal">冲正响应</param>
		RtnRepealFromBankToFutureByFutureManualArgs(RspRepealField^ pRspRepeal)
		{
			this->pRspRepeal = pRspRepeal;
		}
	};

	/// <summary>
	/// 系统运行时期货端手工发起冲正期货转银行请求，银行处理完毕后报盘发回的通知事件参数
	/// </summary>
	public ref class RtnRepealFromFutureToBankByFutureManualArgs : System::EventArgs
	{
	public:
		RspRepealField^ pRspRepeal;

		/// <summary>
		/// 系统运行时期货端手工发起冲正期货转银行请求，银行处理完毕后报盘发回的通知事件参数
		/// </summary>
		/// <param name="pRspRepeal">冲正响应</param>
		RtnRepealFromFutureToBankByFutureManualArgs(RspRepealField^ pRspRepeal)
		{
			this->pRspRepeal = pRspRepeal;
		}
	};

	/// <summary>
	/// 期货发起查询银行余额通知事件参数
	/// </summary>
	public ref class RtnQueryBankBalanceByFutureArgs : System::EventArgs
	{
	public:
		NotifyQueryAccountField^ pNotifyQueryAccount;

		/// <summary>
		/// 期货发起查询银行余额通知事件参数
		/// </summary>
		/// <param name="pNotifyQueryAccount">查询账户信息通知</param>
		RtnQueryBankBalanceByFutureArgs(NotifyQueryAccountField^ pNotifyQueryAccount)
		{
			this->pNotifyQueryAccount = pNotifyQueryAccount;
		}
	};

	/// <summary>
	/// 期货发起银行资金转期货错误回报事件参数
	/// </summary>
	public ref class ErrRtnBankToFutureByFutureArgs : System::EventArgs
	{
	public:
		ReqTransferField^ pReqTransfer;
		RspInfoField^ pRspInfo;

		/// <summary>
		/// 期货发起银行资金转期货错误回报事件参数
		/// </summary>
		/// <param name="pReqTransfer">转账请求</param>
		/// <param name="pRspInfo">响应信息</param>
		ErrRtnBankToFutureByFutureArgs(ReqTransferField^ pReqTransfer, RspInfoField^ pRspInfo)
		{
			this->pReqTransfer = pReqTransfer;
		}
	};

	/// <summary>
	/// 期货发起期货资金转银行错误回报事件参数
	/// </summary>
	public ref class ErrRtnFutureToBankByFutureArgs : System::EventArgs
	{
	public:
		ReqTransferField^ pReqTransfer;
		RspInfoField^ pRspInfo;

		/// <summary>
		/// 期货发起期货资金转银行错误回报事件参数
		/// </summary>
		/// <param name="pReqTransfer">转账请求</param>
		/// <param name="pRspInfo">响应信息</param>
		ErrRtnFutureToBankByFutureArgs(ReqTransferField^ pReqTransfer, RspInfoField^ pRspInfo)
		{
			this->pReqTransfer = pReqTransfer;
		}
	};

	/// <summary>
	/// 系统运行时期货端手工发起冲正银行转期货错误回报事件参数
	/// </summary>
	public ref class ErrRtnRepealBankToFutureByFutureManualArgs : System::EventArgs
	{
	public:
		ReqRepealField^ pReqRepeal;
		RspInfoField^ pRspInfo;

		/// <summary>
		/// 系统运行时期货端手工发起冲正银行转期货错误回报事件参数
		/// </summary>
		/// <param name="pReqRepeal">冲正请求</param>
		/// <param name="pRspInfo">响应信息</param>
		ErrRtnRepealBankToFutureByFutureManualArgs(ReqRepealField^ pReqRepeal, RspInfoField^ pRspInfo)
		{
			this->pReqRepeal = pReqRepeal;
		}
	};

	/// <summary>
	/// 系统运行时期货端手工发起冲正期货转银行错误回报事件参数
	/// </summary>
	public ref class ErrRtnRepealFutureToBankByFutureManualArgs : System::EventArgs
	{
	public:
		ReqRepealField^ pReqRepeal;
		RspInfoField^ pRspInfo;

		/// <summary>
		/// 系统运行时期货端手工发起冲正期货转银行错误回报事件参数
		/// </summary>
		/// <param name="pReqRepeal">冲正请求</param>
		/// <param name="pRspInfo">响应信息</param>
		ErrRtnRepealFutureToBankByFutureManualArgs(ReqRepealField^ pReqRepeal, RspInfoField^ pRspInfo)
		{
			this->pReqRepeal = pReqRepeal;
		}
	};

	/// <summary>
	/// 期货发起查询银行余额错误回报事件参数
	/// </summary>
	public ref class ErrRtnQueryBankBalanceByFutureArgs : System::EventArgs
	{
	public:
		ReqQueryAccountField^ pReqQueryAccount;
		RspInfoField^ pRspInfo;

		/// <summary>
		/// 期货发起查询银行余额错误回报事件参数
		/// </summary>
		/// <param name="pReqQueryAccount">查询账户信息请求</param>
		/// <param name="pRspInfo">响应信息</param>
		ErrRtnQueryBankBalanceByFutureArgs(ReqQueryAccountField^ pReqQueryAccount, RspInfoField^ pRspInfo)
		{
			this->pReqQueryAccount = pReqQueryAccount;
		}
	};

	/// <summary>
	/// 期货发起冲正银行转期货请求，银行处理完毕后报盘发回的通知事件参数
	/// </summary>
	public ref class RtnRepealFromBankToFutureByFutureArgs : System::EventArgs
	{
	public:
		RspRepealField^ pRspRepeal;

		/// <summary>
		/// 期货发起冲正银行转期货请求，银行处理完毕后报盘发回的通知事件参数
		/// </summary>
		/// <param name="pRspRepeal">冲正响应</param>
		RtnRepealFromBankToFutureByFutureArgs(RspRepealField^ pRspRepeal)
		{
			this->pRspRepeal = pRspRepeal;
		}
	};

	/// <summary>
	/// 期货发起冲正期货转银行请求，银行处理完毕后报盘发回的通知事件参数
	/// </summary>
	public ref class RtnRepealFromFutureToBankByFutureArgs : System::EventArgs
	{
	public:
		RspRepealField^ pRspRepeal;

		/// <summary>
		/// 期货发起冲正期货转银行请求，银行处理完毕后报盘发回的通知事件参数
		/// </summary>
		/// <param name="pRspRepeal">冲正响应</param>
		RtnRepealFromFutureToBankByFutureArgs(RspRepealField^ pRspRepeal)
		{
			this->pRspRepeal = pRspRepeal;
		}
	};

	/// <summary>
	/// 期货发起银行资金转期货应答事件参数
	/// </summary>
	public ref class RspFromBankToFutureByFutureArgs : BasicArgs
	{
	public:
		ReqTransferField^ pReqTransfer;

		/// <summary>
		/// 期货发起银行资金转期货应答事件参数
		/// </summary>
		/// <param name="pReqTransfer">转账请求</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspFromBankToFutureByFutureArgs(ReqTransferField^ pReqTransfer, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pReqTransfer = pReqTransfer;
		}
	};

	/// <summary>
	/// 期货发起期货资金转银行应答事件参数
	/// </summary>
	public ref class RspFromFutureToBankByFutureArgs : BasicArgs
	{
	public:
		ReqTransferField^ pReqTransfer;

		/// <summary>
		/// 期货发起期货资金转银行应答事件参数
		/// </summary>
		/// <param name="pReqTransfer">转账请求</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspFromFutureToBankByFutureArgs(ReqTransferField^ pReqTransfer, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pReqTransfer = pReqTransfer;
		}
	};

	/// <summary>
	/// 期货发起查询银行余额应答事件参数
	/// </summary>
	public ref class RspQueryBankAccountMoneyByFutureArgs : BasicArgs
	{
	public:
		ReqQueryAccountField^ pReqQueryAccount;

		/// <summary>
		/// 期货发起查询银行余额应答事件参数
		/// </summary>
		/// <param name="pReqQueryAccount">查询账户信息请求</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQueryBankAccountMoneyByFutureArgs(ReqQueryAccountField^ pReqQueryAccount, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pReqQueryAccount = pReqQueryAccount;
		}
	};

	/// <summary>
	/// 银行发起银期开户通知事件参数
	/// </summary>
	public ref class RtnOpenAccountByBankArgs : System::EventArgs
	{
	public:
		OpenAccountField^ pOpenAccount;

		/// <summary>
		/// 银行发起银期开户通知事件参数
		/// </summary>
		/// <param name="pOpenAccount">银期开户信息</param>
		RtnOpenAccountByBankArgs(OpenAccountField^ pOpenAccount)
		{
			this->pOpenAccount = pOpenAccount;
		}
	};

	/// <summary>
	/// 银行发起银期销户通知事件参数
	/// </summary>
	public ref class RtnCancelAccountByBankArgs : System::EventArgs
	{
	public:
		CancelAccountField^ pCancelAccount;

		/// <summary>
		/// 银行发起银期销户通知事件参数
		/// </summary>
		/// <param name="pCancelAccount">银期销户信息</param>
		RtnCancelAccountByBankArgs(CancelAccountField^ pCancelAccount)
		{
			this->pCancelAccount = pCancelAccount;
		}
	};

	/// <summary>
	/// 银行发起变更银行账号通知事件参数
	/// </summary>
	public ref class RtnChangeAccountByBankArgs : System::EventArgs
	{
	public:
		ChangeAccountField^ pChangeAccount;

		/// <summary>
		/// 银行发起变更银行账号通知事件参数
		/// </summary>
		/// <param name="pChangeAccount">银期变更银行账号信息</param>
		RtnChangeAccountByBankArgs(ChangeAccountField^ pChangeAccount)
		{
			this->pChangeAccount = pChangeAccount;
		}
	};

	/// <summary>
	/// 请求查询分类合约响应事件参数
	/// </summary>
	public ref class RspQryClassifiedInstrumentArgs : BasicArgs
	{
	public:
		InstrumentField^ pInstrument;

		/// <summary>
		/// 请求查询分类合约响应事件参数
		/// </summary>
		/// <param name="pInstrument">合约</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQryClassifiedInstrumentArgs(InstrumentField^ pInstrument, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pInstrument = pInstrument;
		}
	};

	/// <summary>
	/// 请求组合优惠比例响应事件参数
	/// </summary>
	public ref class RspQryCombPromotionParamArgs : BasicArgs
	{
	public:
		CombPromotionParamField^ pCombPromotionParam;

		/// <summary>
		/// 请求组合优惠比例响应事件参数
		/// </summary>
		/// <param name="pCombPromotionParam">组合优惠比例</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQryCombPromotionParamArgs(CombPromotionParamField^ pCombPromotionParam, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pCombPromotionParam = pCombPromotionParam;
		}
	};

	/// <summary>
	/// 投资者风险结算持仓查询响应事件参数
	/// </summary>
	public ref class RspQryRiskSettleInvstPositionArgs : BasicArgs
	{
	public:
		RiskSettleInvstPositionField^ pRiskSettleInvstPosition;

		/// <summary>
		/// 投资者风险结算持仓查询响应事件参数
		/// </summary>
		/// <param name="pRiskSettleInvstPosition">投资者风险结算持仓</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQryRiskSettleInvstPositionArgs(RiskSettleInvstPositionField^ pRiskSettleInvstPosition, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pRiskSettleInvstPosition = pRiskSettleInvstPosition;
		}
	};

	/// <summary>
	/// 风险结算产品查询响应事件参数
	/// </summary>
	public ref class RspQryRiskSettleProductStatusArgs : BasicArgs
	{
	public:
		RiskSettleProductStatusField^ pRiskSettleProductStatus;

		/// <summary>
		/// 风险结算产品查询响应事件参数
		/// </summary>
		/// <param name="pRiskSettleProductStatus">风险品种</param>
		/// <param name="pRspInfo">响应信息</param>
		/// <param name="nRequestID">请求ID</param>
		/// <param name="bIsLast">响应是否持续</param>
		RspQryRiskSettleProductStatusArgs(RiskSettleProductStatusField^ pRiskSettleProductStatus, RspInfoField^ pRspInfo, int nRequestID, bool bIsLast) : BasicArgs(pRspInfo, nRequestID, bIsLast)
		{
			this->pRiskSettleProductStatus = pRiskSettleProductStatus;
		}
	};


}