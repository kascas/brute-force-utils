#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *key;
    char *end;
    int endLen;
    int currentLen;
} KeyCtx;

// 生成器初始化，start为开始口令，end为结束口令
KeyCtx *KeyGenInit(char *start, char *end)
{
    if (strcmp(start, end) >= 0)
    {
        return NULL;
    }
    KeyCtx *ctx = (KeyCtx *)malloc(sizeof(KeyCtx));
    if (ctx == NULL)
    {
        return NULL;
    }
    ctx->currentLen = strlen(start);
    ctx->endLen = strlen(end);
    ctx->key = (char *)malloc(ctx->endLen + 1);
    ctx->end = (char *)malloc(ctx->endLen + 1);
    if (ctx->key == NULL || ctx->end == NULL)
    {
        return NULL;
    }
    memset(ctx->key, 0, ctx->endLen + 1);
    memcpy(ctx->key + ctx->endLen - ctx->currentLen, start, ctx->currentLen);
    memset(ctx->end, 0, ctx->endLen + 1);
    memcpy(ctx->end, end, ctx->endLen);
    return ctx;
}

// 小写字母口令顺序遍历
char *KeyGenRound_a(KeyCtx *ctx)
{
    ctx->key[ctx->endLen - 1] += 1;
    for (int loc = ctx->endLen - 1; loc >= 0; loc--)
    {
        if (ctx->key[loc] > 'z')
        {
            ctx->key[loc] = 'a';
            if (ctx->key[loc - 1] == 0)
            {
                ctx->currentLen++;
                ctx->key[loc - 1] = 'a';
                break;
            }
            else
            {
                ctx->key[loc - 1] += 1;
            }
        }
        else
        {
            break;
        }
    }
    char *key = ctx->key + (ctx->endLen - ctx->currentLen);
    if (ctx->currentLen < ctx->endLen)
    {
        return key;
    }
    else if (memcmp(key, ctx->end, ctx->endLen) <= 0)
    {
        return key;
    }
    else
    {
        return NULL;
    }
}

// 大写字母口令顺序遍历
char *KeyGenRound_A(KeyCtx *ctx)
{
    ctx->key[ctx->endLen - 1] += 1;
    for (int loc = ctx->endLen - 1; loc >= 0; loc--)
    {
        if (ctx->key[loc] > 'Z')
        {
            ctx->key[loc] = 'A';
            if (ctx->key[loc - 1] == 0)
            {
                ctx->currentLen++;
                ctx->key[loc - 1] = 'A';
                break;
            }
            else
            {
                ctx->key[loc - 1] += 1;
            }
        }
        else
        {
            break;
        }
    }
    char *key = ctx->key + (ctx->endLen - ctx->currentLen);
    if (ctx->currentLen < ctx->endLen)
    {
        return key;
    }
    else if (memcmp(key, ctx->end, ctx->endLen) <= 0)
    {
        return key;
    }
    else
    {
        return NULL;
    }
}

// 纯数字口令顺序遍历
char *KeyGenRound_0(KeyCtx *ctx)
{
    ctx->key[ctx->endLen - 1] += 1;
    for (int loc = ctx->endLen - 1; loc >= 0; loc--)
    {
        if (ctx->key[loc] > '9')
        {
            ctx->key[loc] = '0';
            if (ctx->key[loc - 1] == 0)
            {
                ctx->currentLen++;
                ctx->key[loc - 1] = '1';
                break;
            }
            else
            {
                ctx->key[loc - 1] += 1;
            }
        }
        else
        {
            break;
        }
    }
    char *key = ctx->key + (ctx->endLen - ctx->currentLen);
    if (ctx->currentLen < ctx->endLen)
    {
        return key;
    }
    else if (memcmp(key, ctx->end, ctx->endLen) <= 0)
    {
        return key;
    }
    else
    {
        return NULL;
    }
}

// 小写字母与数字混合口令顺序遍历
char *KeyGenRound_a0(KeyCtx *ctx)
{
    ctx->key[ctx->endLen - 1] += 1;
    for (int loc = ctx->endLen - 1; loc >= 0; loc--)
    {
        if (ctx->key[loc] > '9' && ctx->key[loc] < 'a')
        {
            ctx->key[loc] = 'a';
            break;
        }
        if (ctx->key[loc] > 'z')
        {
            ctx->key[loc] = '0';
            if (ctx->key[loc - 1] == 0)
            {
                ctx->currentLen++;
                ctx->key[loc - 1] = '1';
                break;
            }
            else
            {
                ctx->key[loc - 1] += 1;
            }
        }
        else
        {
            break;
        }
    }
    char *key = ctx->key + (ctx->endLen - ctx->currentLen);
    if (ctx->currentLen < ctx->endLen)
    {
        return key;
    }
    else if (memcmp(key, ctx->end, ctx->endLen) <= 0)
    {
        return key;
    }
    else
    {
        return NULL;
    }
}

// 大写字母与数字混合口令顺序遍历
char *KeyGenRound_A0(KeyCtx *ctx)
{
    ctx->key[ctx->endLen - 1] += 1;
    for (int loc = ctx->endLen - 1; loc >= 0; loc--)
    {
        if (ctx->key[loc] > '9' && ctx->key[loc] < 'A')
        {
            ctx->key[loc] = 'A';
            break;
        }
        if (ctx->key[loc] > 'Z')
        {
            ctx->key[loc] = '0';
            if (ctx->key[loc - 1] == 0)
            {
                ctx->currentLen++;
                ctx->key[loc - 1] = '1';
                break;
            }
            else
            {
                ctx->key[loc - 1] += 1;
            }
        }
        else
        {
            break;
        }
    }
    char *key = ctx->key + (ctx->endLen - ctx->currentLen);
    if (ctx->currentLen < ctx->endLen)
    {
        return key;
    }
    else if (memcmp(key, ctx->end, ctx->endLen) <= 0)
    {
        return key;
    }
    else
    {
        return NULL;
    }
}

// 大写字母口令顺序遍历
char *KeyGenRound_aA(KeyCtx *ctx)
{
    ctx->key[ctx->endLen - 1] += 1;
    for (int loc = ctx->endLen - 1; loc >= 0; loc--)
    {
        if ((ctx->key[loc] > 'Z' && ctx->key[loc] < 'a') || (ctx->key[loc] > '9' && ctx->key[loc] < 'A'))
        {
            ctx->key[loc] = 'a';
            break;
        }
        if (ctx->key[loc] > 'z')
        {
            ctx->key[loc] = 'A';
            if (ctx->key[loc - 1] == 0)
            {
                ctx->currentLen++;
                ctx->key[loc - 1] = 'A';
                break;
            }
            else
            {
                ctx->key[loc - 1] += 1;
            }
        }
        else
        {
            break;
        }
    }
    char *key = ctx->key + (ctx->endLen - ctx->currentLen);
    if (ctx->currentLen < ctx->endLen)
    {
        return key;
    }
    else if (memcmp(key, ctx->end, ctx->endLen) <= 0)
    {
        return key;
    }
    else
    {
        return NULL;
    }
}

// 大小写字母与数字混合口令顺序遍历
char *KeyGenRound_aA0(KeyCtx *ctx)
{
    ctx->key[ctx->endLen - 1] += 1;
    for (int loc = ctx->endLen - 1; loc >= 0; loc--)
    {
        if (ctx->key[loc] > '9' && ctx->key[loc] < 'A')
        {
            ctx->key[loc] = 'A';
            break;
        }
        if (ctx->key[loc] > 'Z' && ctx->key[loc] < 'a')
        {
            ctx->key[loc] = 'a';
            break;
        }
        if (ctx->key[loc] > 'z')
        {
            ctx->key[loc] = '0';
            if (ctx->key[loc - 1] == 0)
            {
                ctx->currentLen++;
                ctx->key[loc - 1] = '1';
                break;
            }
            else
            {
                ctx->key[loc - 1] += 1;
            }
        }
        else
        {
            break;
        }
    }
    char *key = ctx->key + (ctx->endLen - ctx->currentLen);
    if (ctx->currentLen < ctx->endLen)
    {
        return key;
    }
    else if (memcmp(key, ctx->end, ctx->endLen) <= 0)
    {
        return key;
    }
    else
    {
        return NULL;
    }
}

// 生成器使用结束后释放内存
void KeyGenFree(KeyCtx *ctx)
{
    if (ctx != NULL)
    {
        if (ctx->end != NULL)
        {
            free(ctx->key);
        }
        free(ctx);
    }
}

int main()
{
    KeyCtx *ctx = KeyGenInit("Z000", "zzzz");
    if (ctx == NULL)
    {
        printf("CTX == NULL !!!\n");
        return -1;
    }

    char *key = "";
    while (key != NULL)
    {
        key = KeyGenRound_a(ctx);
        // key = KeyGenRound_A(ctx);
        // key = KeyGenRound_0(ctx);
        // key = KeyGenRound_a0(ctx);
        // key = KeyGenRound_A0(ctx);
        // key = KeyGenRound_aA(ctx);
        // key = KeyGenRound_aA0(ctx);
        printf("%s\n", key);
    }
    system("pause");
    return 0;
}