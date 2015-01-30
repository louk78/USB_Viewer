#pragma once


enum
{
	//���³������������ɵ�״̬
	WM_MYMSG = WM_USER + 1,
	FORMAT_OK,
	FORMAT_ERROR,
	UNZIP_OK,
	UNZIP_ERROR,

	NO_Active_Partition,		//����CCreateStartDlg::GetActivePartitionNum()����, ��ʾ�Ҳ��������
};

const DWORD FAT32_SIZE_LIMIT = 35;		//format����Ҫ��fat32 > 35m
const DWORD NTFS_SIZE_LIMIT = 2;		//format����Ҫ��ntfs > 2m

struct Partition_Table
{
	CHAR type[8];						//ֻ��"ntfs"��"fat32"��Ч
	unsigned long long size;			//��MBΪ��λ		(ULONG64)
};

struct FormatPartitionArg
{
	HANDLE hDrv;
	CHAR drive[3];
	INT num;
	Partition_Table* list;
	HWND msgWnd;
	CHAR eventName[10];
};

struct UnZipArg
{
	CHAR desPath[MAX_PATH];
	CHAR exePath[MAX_PATH];
	CHAR isoPath[MAX_PATH];
	HWND msgWnd;
};