#pragma once
#include <string.h>
#include "pch.h"
#include "Functions.h"

namespace PhoenixCTP
{
	/// <summary>
	/// Fens用户信息
	/// </summary>
	public ref struct FensUserInfoField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		System::String^ BrokerID;
		/// <summary>
		/// 用户代码
		/// </summary>
		System::String^ UserID;
		/// <summary>
		/// 登录模式
		/// </summary>
		char LoginMode;

		/// <summary>
		/// 将本结构体转化成非托管的结构体类型
		/// </summary>
		/// <returns>新生成的非托管类型结构体指针</returns>
		CThostFtdcFensUserInfoField* getUnmanagedStructP(void)
		{
			CThostFtdcFensUserInfoField* result = new CThostFtdcFensUserInfoField();
			strcpy_s(result->BrokerID, netString2ConstChar(BrokerID));
			strcpy_s(result->UserID, netString2ConstChar(UserID));
			result->LoginMode = LoginMode;
			return result;
		}
	};

	/// <summary>
	/// 用户登录应答
	/// </summary>
	public ref struct RspUserLoginField
	{
		/// <summary>
		/// 交易日
		/// </summary>
		System::String^ TradingDay;
		/// <summary>
		/// 登陆成功时间
		/// </summary>
		System::String^ LoginTime;
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		System::String^ BrokerID;
		/// <summary>
		/// 用户代码
		/// </summary>
		System::String^ UserID;
		/// <summary>
		/// 交易系统名称
		/// </summary>
		System::String^ SystemName;

		/// <summary>
		/// 前置编号
		/// </summary>
		int FrontID;

		/// <summary>
		/// 会话编号
		/// </summary>
		int SessionID;

		/// <summary>
		/// 最大报单引用
		/// </summary>
		System::String^ MaxOrderRef;

		/// <summary>
		/// 上期所时间
		/// </summary>
		System::String^ SHFETime;

		/// <summary>
		/// 大商所时间
		/// </summary>
		System::String^ DCETime;

		/// <summary>
		/// 郑商所时间
		/// </summary>
		System::String^ CZCETime;

		/// <summary>
		/// 中金所时间
		/// </summary>
		System::String^ FFEXTime;

		/// <summary>
		/// 能源中心时间
		/// </summary>
		System::String^ INETime;

		/// <summary>
		/// 使用C++用户登录应答初始化本结构体当中的成员变量
		/// </summary>
		/// <param name="source">指向原始登陆应答结构体的指针</param>
		void initFromUnmanagedStruct(CThostFtdcRspUserLoginField* source)
		{
			TradingDay = char2NetString(source->TradingDay);
			LoginTime = char2NetString(source->LoginTime);
			BrokerID = char2NetString(source->BrokerID);
			UserID = char2NetString(source->UserID);
			SystemName = char2NetString(source->SystemName);
			FrontID = source->FrontID;
			SessionID = source->SessionID;
			MaxOrderRef = char2NetString(source->MaxOrderRef);
			SHFETime = char2NetString(source->SHFETime);
			DCETime = char2NetString(source->DCETime);
			CZCETime = char2NetString(source->CZCETime);
			FFEXTime = char2NetString(source->CZCETime);
			INETime = char2NetString(source->INETime);
		}

		/// <summary>
		/// 使用C++用户登录应答初始化构造本结构体
		/// </summary>
		/// <param name="source">指向原始登陆应答结构体的指针</param>
		RspUserLoginField(CThostFtdcRspUserLoginField* source)
		{
			initFromUnmanagedStruct(source);
		}
	};

	/// <summary>
	/// 响应信息
	/// </summary>
	public ref struct RspInfoField
	{
		/// <summary>
		/// 错误代码
		/// </summary>
		int ErrorID;
		/// <summary>
		/// 错误信息
		/// </summary>
		System::String^ ErrorMsg;

		/// <summary>
		/// 使用C++响应信息初始化本结构体当中的成员变量
		/// </summary>
		/// <param name="source">指向原始响应信息结构体的指针</param>
		void initFromUnmanagedStruct(CThostFtdcRspInfoField* source)
		{
			ErrorID = source->ErrorID;
			ErrorMsg = char2NetString(source->ErrorMsg);
		}

		/// <summary>
		/// 使用C++响应信息初始化构造本结构体
		/// </summary>
		/// <param name="source">指向原始响应信息结构体的指针</param>
		RspInfoField(CThostFtdcRspInfoField* source)
		{
			initFromUnmanagedStruct(source);
		}
	};

	/// <summary>
	/// 用户登出请求
	/// </summary>
	public ref struct UserLogoutField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		System::String^ BrokerID;
		/// <summary>
		/// 用户代码
		/// </summary>
		System::String^ UserID;

		/// <summary>
		/// 使用C++用户登出请求结构体初始化本结构体当中的成员变量
		/// </summary>
		/// <param name="source">指向原始用户登出请求结构体的指针</param>
		void initFromUnmanagedStruct(CThostFtdcUserLogoutField* source)
		{
			BrokerID = char2NetString(source->BrokerID);
			UserID = char2NetString(source->UserID);
		}

		/// <summary>
		/// 使用C++用户登出请求结构体初始化构造本结构体
		/// </summary>
		/// <param name="source">指向原始用户登出请求结构体的指针</param>
		UserLogoutField(CThostFtdcUserLogoutField* source)
		{
			initFromUnmanagedStruct(source);
		}
	};

	/// <summary>
	/// 组播合约
	/// </summary>
	public ref struct MulticastInstrumentField
	{
		/// <summary>
		/// 主题号
		/// </summary>
		int TopicID;
		/// <summary>
		/// 合约代码
		/// </summary>
		System::String^ InstrumentID;
		/// <summary>
		/// 合约编号
		/// </summary>
		int InstrumentNo;
		/// <summary>
		/// 基准价
		/// </summary>
		double CodePrice;
		/// <summary>
		/// 合约数量乘数
		/// </summary>
		int VolumeMultiple;
		/// <summary>
		/// 最小变动价位
		/// </summary>
		double PriceTick;


		/// <summary>
		/// 使用C++组播合约结构体初始化本结构体当中的成员变量
		/// </summary>
		/// <param name="source">指向原始组播合约结构体的指针</param>
		void initFromUnmanagedStruct(CThostFtdcMulticastInstrumentField* source)
		{
			TopicID = source->TopicID;
			InstrumentID = char2NetString(source->InstrumentID);
			InstrumentNo = source->InstrumentNo;
			CodePrice = source->CodePrice;
			VolumeMultiple = source->VolumeMultiple;
			PriceTick = source->PriceTick;
		}

		/// <summary>
		/// 使用C++组播合约结构体初始化构造本结构体
		/// </summary>
		/// <param name="source">指向原始组播合约结构体的指针</param>
		MulticastInstrumentField(CThostFtdcMulticastInstrumentField* source)
		{
			initFromUnmanagedStruct(source);
		}
	};

	/// <summary>
	/// 指定的合约
	/// </summary>
	public ref struct SpecificInstrumentField
	{
		/// <summary>
		/// 合约代码
		/// </summary>
		System::String^ InstrumentID;

		/// <summary>
		/// 使用C++指定合约结构体初始化本结构体当中的成员变量
		/// </summary>
		/// <param name="source">指向原始指定合约结构体的指针</param>
		void initFromUnmanagedStruct(CThostFtdcSpecificInstrumentField* source)
		{
			InstrumentID = char2NetString(source->InstrumentID);
		}

		/// <summary>
		/// 使用C++指定合约结构体初始化构造本结构体
		/// </summary>
		/// <param name="source">指向原始指定合约结构体的指针</param>
		SpecificInstrumentField(CThostFtdcSpecificInstrumentField* source)
		{
			initFromUnmanagedStruct(source);
		}
	};

	/// <summary>
	/// 深度行情
	/// </summary>
	public ref struct DepthMarketDataField
	{
		/// <summary>
		/// 交易日
		/// </summary>
		System::String^ TradingDay;
		/// <summary>
		/// 合约代码
		/// </summary>
		System::String^ InstrumentID;
		/// <summary>
		/// 交易所代码
		/// </summary>
		System::String^ ExchangeID;
		/// <summary>
		/// 合约在交易所的代码
		/// </summary>
		System::String^ ExchangeInstID;
		/// <summary>
		/// 最新价
		/// </summary>
		double LastPrice;
		/// <summary>
		/// 上次结算价
		/// </summary>
		double PreSettlementPrice;
		/// <summary>
		/// 昨收盘
		/// </summary>
		double PreClosePrice;
		/// <summary>
		/// 昨持仓量
		/// </summary>
		double PreOpenInterest;
		/// <summary>
		/// 今开盘
		/// </summary>
		double OpenPrice;
		/// <summary>
		/// 最高价
		/// </summary>
		double HighestPrice;
		/// <summary>
		/// 最低价
		/// </summary>
		double LowestPrice;
		/// <summary>
		/// 数量
		/// </summary>
		int Volume;
		/// <summary>
		/// 成交金额
		/// </summary>
		double Turnover;
		/// <summary>
		/// 持仓量
		/// </summary>
		double OpenInterest;
		/// <summary>
		/// 今收盘
		/// </summary>
		double ClosePrice;
		/// <summary>
		/// 本次结算价
		/// </summary>
		double SettlementPrice;
		/// <summary>
		/// 涨停板价
		/// </summary>
		double UpperLimitPrice;
		/// <summary>
		/// 跌停板价
		/// </summary>
		double LowerLimitPrice;
		/// <summary>
		/// 昨虚实度
		/// </summary>
		double PreDelta;
		/// <summary>
		/// 今虚实度
		/// </summary>
		double CurrDelta;
		/// <summary>
		/// 最后修改时间
		/// </summary>
		System::String^ UpdateTime;
		/// <summary>
		/// 最后修改毫秒
		/// </summary>
		int UpdateMillisec;
		/// <summary>
		/// 申买价一
		/// </summary>
		double BidPrice1;
		/// <summary>
		/// 申买量一
		/// </summary>
		int BidVolume1;
		/// <summary>
		/// 申卖价一
		/// </summary>
		double AskPrice1;
		/// <summary>
		/// 申卖量一
		/// </summary>
		int AskVolume1;
		/// <summary>
		/// 申买价二
		/// </summary>
		double BidPrice2;
		/// <summary>
		/// 申买量二
		/// </summary>
		int BidVolume2;
		/// <summary>
		/// 申卖价二
		/// </summary>
		double AskPrice2;
		/// <summary>
		/// 申卖量二
		/// </summary>
		int AskVolume2;
		/// <summary>
		/// 申买价三
		/// </summary>
		double BidPrice3;
		/// <summary>
		/// 申买量三
		/// </summary>
		int BidVolume3;
		/// <summary>
		/// 申卖价三
		/// </summary>
		double AskPrice3;
		/// <summary>
		/// 申卖量三
		/// </summary>
		int AskVolume3;
		/// <summary>
		/// 申买价四
		/// </summary>
		double BidPrice4;
		/// <summary>
		/// 申买量四
		/// </summary>
		int BidVolume4;
		/// <summary>
		/// 申卖价四
		/// </summary>
		double AskPrice4;
		/// <summary>
		/// 申卖量四
		/// </summary>
		int AskVolume4;
		/// <summary>
		/// 申买价五
		/// </summary>
		double BidPrice5;
		/// <summary>
		/// 申买量五
		/// </summary>
		int BidVolume5;
		/// <summary>
		/// 申卖价五
		/// </summary>
		double AskPrice5;
		/// <summary>
		/// 申卖量五
		/// </summary>
		int AskVolume5;
		/// <summary>
		/// 当日均价
		/// </summary>
		double AveragePrice;
		/// <summary>
		/// 业务日期
		/// </summary>
		System::String^ ActionDay;

		/// <summary>
		/// 使用C++深度行情结构体初始化本结构体当中的成员变量
		/// </summary>
		/// <param name="source">指向原始深度行情结构体的指针</param>
		void initFromUnmanagedStruct(CThostFtdcDepthMarketDataField* source)
		{
			TradingDay = char2NetString(source->TradingDay);
			InstrumentID = char2NetString(source->InstrumentID);
			ExchangeID = char2NetString(source->ExchangeID);
			ExchangeInstID = char2NetString(source->ExchangeInstID);
			LastPrice = source->LastPrice;
			PreSettlementPrice = source->PreSettlementPrice;
			PreClosePrice = source->PreClosePrice;
			PreOpenInterest = source->PreOpenInterest;
			OpenPrice = source->OpenPrice;
			HighestPrice = source->HighestPrice;
			LowestPrice = source->LowestPrice;
			Volume = source->Volume;
			Turnover = source->Turnover;
			OpenInterest = source->OpenInterest;
			ClosePrice = source->ClosePrice;
			SettlementPrice = source->SettlementPrice;
			UpperLimitPrice = source->UpperLimitPrice;
			LowerLimitPrice = source->LowerLimitPrice;
			PreDelta = source->PreDelta;
			CurrDelta = source->CurrDelta;
			UpdateTime = char2NetString(source->UpdateTime);
			UpdateMillisec = source->UpdateMillisec;
			BidPrice1 = source->BidPrice1;
			BidVolume1 = source->BidVolume1;
			AskPrice1 = source->AskPrice1;
			AskVolume1 = source->AskVolume1;
			BidPrice2 = source->BidPrice2;
			BidVolume2 = source->BidVolume2;
			AskPrice2 = source->AskPrice2;
			AskVolume2 = source->AskVolume2;
			BidPrice3 = source->BidPrice3;
			BidVolume3 = source->BidVolume3;
			AskPrice3 = source->AskPrice3;
			AskVolume3 = source->AskVolume3;
			BidPrice4 = source->BidPrice4;
			BidVolume4 = source->BidVolume4;
			AskPrice4 = source->AskPrice4;
			AskVolume4 = source->AskVolume4;
			BidPrice5 = source->BidPrice5;
			BidVolume5 = source->BidVolume5;
			AskPrice5 = source->AskPrice5;
			AskVolume5 = source->AskVolume5;
			AveragePrice = source->AveragePrice;
			ActionDay = char2NetString(source->ActionDay);
		}

		/// <summary>
		/// 使用C++深度行情结构体初始化构造本结构体
		/// </summary>
		/// <param name="source">指向原始深度行情结构体的指针</param>
		DepthMarketDataField(CThostFtdcDepthMarketDataField* source)
		{
			initFromUnmanagedStruct(source);
		}
	};

	/// <summary>
	/// 发给做市商的询价请求
	/// </summary>
	public ref struct ForQuoteRspField
	{
		/// <summary>
		/// 交易日
		/// </summary>
		System::String^ TradingDay;
		/// <summary>
		/// 合约代码
		/// </summary>
		System::String^ InstrumentID;
		/// <summary>
		/// 询价编号
		/// </summary>
		System::String^ ForQuoteSysID;
		/// <summary>
		/// 询价时间
		/// </summary>
		System::String^ ForQuoteTime;
		/// <summary>
		/// 业务日期
		/// </summary>
		System::String^ ActionDay;
		/// <summary>
		/// 交易所代码
		/// </summary>
		System::String^ ExchangeID;


		/// <summary>
		/// 使用C++发给做市商的询价请求结构体初始化本结构体当中的成员变量
		/// </summary>
		/// <param name="source">指向原始发给做市商的询价请求结构体的指针</param>
		void initFromUnmanagedStruct(CThostFtdcForQuoteRspField* source)
		{
			TradingDay = char2NetString(source->TradingDay);
			InstrumentID = char2NetString(source->InstrumentID);
			ForQuoteSysID = char2NetString(source->ForQuoteSysID);
			ForQuoteTime = char2NetString(source->ForQuoteTime);
			ActionDay = char2NetString(source->ActionDay);
			ExchangeID = char2NetString(source->ExchangeID);
		}

		/// <summary>
		/// 使用C++发给做市商的询价请求结构体初始化构造本结构体
		/// </summary>
		/// <param name="source">指向原始发给做市商的询价请求结构体的指针</param>
		ForQuoteRspField(CThostFtdcForQuoteRspField* source)
		{
			initFromUnmanagedStruct(source);
		}
	};

}
