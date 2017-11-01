// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 GOBANGCORE_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// GOBANGCORE_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
#ifdef GOBANGCORE_EXPORTS
#define GOBANGCORE_API __declspec(dllexport)
#else
#define GOBANGCORE_API __declspec(dllimport)
#endif

/*// 此类是从 gobangCore.dll 导出的
class GOBANGCORE_API CgobangCore {
public:
	CgobangCore(void);
	// TODO:  在此添加您的方法。
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