#ifndef STRING_WRAPPER
#define STRING_WRAPPER
#ifdef __cplusplus
extern "C"{
#endif // __cplusplus
    // interface data type
    struct GSTR;
    typedef       struct GSTR *PGSTRV; // pointers only
    typedef const struct GSTR *PGSTRC; // pointers only
    // constructor/destructor
    PGSTRV NewGSTR_Empty();
    PGSTRV NewGSTR_ByStr(const char *src);
    PGSTRV NewGSTR_Blank(int size);
    void   GSTRDestroy(PGSTRV pthis);
    void   GSTRImport(PGSTRV pthis, const char *src);
    void   GSTRExport(PGSTRC pthis, char *dst);
    // read
    int  GSTRLen(PGSTRC s);
    int  GSTRCmp(PGSTRC a, PGSTRC b);
    int  GSTRFindChr(PGSTRC s, char c);
    int  GSTRFindStr(PGSTRC s, const char *sub);
    // write
    void GSTRCpy(PGSTRV d, PGSTRC s);
    void GSTRCat(PGSTRV d, PGSTRC s);
    void GSTRIns(PGSTRV d, PGSTRC s, int pos);
    void GSTRDel(PGSTRV d, int pos, int len);


#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !STRING_WRAPPER
