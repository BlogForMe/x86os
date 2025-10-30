/**
 * 功能：32位代码，完成多任务的运行
 *
 *创建时间：2022年8月31日
 *作者：李述铜
 *联系邮箱: 527676163@qq.com
 *相关信息：此工程为《从0写x86 Linux操作系统》的前置课程，用于帮助预先建立对32位x86体系结构的理解。整体代码量不到200行（不算注释）
 *课程请见：https://study.163.com/course/introduction.htm?courseId=1212765805&_trace_c_p_k2_=0bdf1e7edda543a8b9a0ad73b5100990
 */
#include "os.h"

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;


#define PDE_P  (1<<0)
#define PDE_W  (1<<1)
#define PDE_U  (1<<2)   
#define PED_PS (1<<7)

uint32_t pg_dir[1024] __attribute__((aligned(4096))) = {
    [0] = (0x00000000 | PDE_P | PDE_W | PDE_U | PED_PS), //0~4MB
    [768] = (0x00000000 | PDE_P | PDE_W | PDE_U | PED_PS), //3GB~3GB+4MB
}





struct {uint16_t limit_l,base_l,basehl_attr,base_limit;}gdt_table[256] __attribute__((aligned(8))) =
{
    [KERNEL_CODE_SEG / 8] = {0xFFFF,0x0000,0x9A00,0x00CF},
    [KERNEL_DATA_SEG / 8] = {0xFFFF,0x0000,0x9200,0x00CF},
};
