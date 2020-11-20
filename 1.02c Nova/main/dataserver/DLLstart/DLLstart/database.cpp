#include "stdafx.h"

DataBase database;

DataBase::DataBase()
{
	this->sa = new SAConnection();
	this->ex = new SACommand();
}

DataBase::~DataBase()
{
	this->sa->Disconnect();
}

void DataBase::Connect()
{
	try
	{
	    this->sa->Connect("MuOnline","","",SA_ODBC_Client);
		this->ex->setConnection(this->sa);
	}
	catch(SAException error)
	{
		MessageBoxA(0,error.ErrText(),"DataBase::Connect",0);
		ExitProcess(1);
	}
}

int DataBase::AccountVIP(char * account)
{
	int vip = 0;

	try
	{
		this->ex->setCommandText(cfg.vip[0]);
		this->ex->Param(1).setAsString() = account;
		this->ex->Execute();

		if(this->ex->isResultSet())
		{
			this->ex->FetchNext();
			vip = this->ex->Field(cfg.vip[1]).asLong();
		}

		this->ex->Close();

		LogAddFuncColor(3,"database sucesso: conta : %s - vip : %d",account,vip);
	}
	catch(SAException error)
	{
		LogAddFuncColor(2,"database erro: conta : %s - coluna vip inválida",account);
		return 0;
	}

	return vip;
}

int DataBase::CharReset(char * name)
{
	int reset = 0;

	try
	{
		this->ex->setCommandText(cfg.resets[0]);
		this->ex->Param(1).setAsString() = name;
		this->ex->Execute();

		if(this->ex->isResultSet())
		{
			this->ex->FetchNext();
			reset = this->ex->Field(cfg.resets[1]).asLong();
		}

		this->ex->Close();

		LogAddFuncColor(3,"database sucesso: nome : %s - resets : %d",name,reset);
	}
	catch(SAException error)
	{
		LogAddFuncColor(2,"database erro: nome : %s - coluna resets inválida",name);
		return 0;
	}

	return reset;
}

void DataBase::WareHouseChange(char * account, WORD ware)
{
	try
	{
		this->ex->setCommandText("EXEC lpObj_change_warehouse :1, :2");
		this->ex->Param(1).setAsString() = account;
		this->ex->Param(2).setAsLong()   = ware;
		this->ex->Execute();
		this->sa->Commit();
		this->ex->Close();
		LogAddFuncColor(3,"database sucesso: conta : %s - bau : %d",account,ware);

	}
	catch(SAException error)
	{
        LogAddFuncColor(2,"database erro: conta : %s - erro ao mudar o bau",account);
	}

}

void DataBase::CharResetUpdate(char * name)
{
	try
	{
		this->ex->setCommandText(cfg.resets[2]);
		this->ex->Param(1).setAsString() = name;
		this->ex->Execute();
		this->sa->Commit();
		this->ex->Close();
		LogAddFuncColor(3,"database sucesso: nome : %s - reset update",name);
	}
	catch(SAException error)
	{
		LogAddFuncColor(2,"database erro: nome : %s - reset update inválido",name);
	}
}