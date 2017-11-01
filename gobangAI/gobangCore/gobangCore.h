// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� GOBANGCORE_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// GOBANGCORE_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef GOBANGCORE_EXPORTS
#define GOBANGCORE_API __declspec(dllexport)
#else
#define GOBANGCORE_API __declspec(dllimport)
#endif

/*// �����Ǵ� gobangCore.dll ������
class GOBANGCORE_API CgobangCore {
public:
	CgobangCore(void);
	// TODO:  �ڴ�������ķ�����
};*/

extern "C" {

	//GOBANGCORE_API extern int chessboard[15][15];
	//GOBANGCORE_API extern int valueboard[15][15];

	GOBANGCORE_API int gobangInit(bool order);
	GOBANGCORE_API int gobangCoreG(int& x, int& y);
	GOBANGCORE_API int gobangCoreS(int& x, int& y);
	GOBANGCORE_API int getChessboard(int x, int y);
	GOBANGCORE_API int getValueboard(int x, int y);
	GOBANGCORE_API int getOrder(); //////
	//GOBANGCORE_API int fngobangCore(void);
}