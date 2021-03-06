
/*
 * Copyright (C) 2011 TIMA Laboratory
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received new_alarm copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef ANNOTATION_MANAGER_PUBLIC_H
#define ANNOTATION_MANAGER_PUBLIC_H

#define USE_ANNOT_BUFF

typedef struct {
    uint32_t          Type;
    uint32_t          InstructionCount;
    uint32_t          CycleCount;
    uint32_t          LoadCount;
    uint32_t          StoreCount;
    uint32_t          FuncAddr;
} annotation_db_t;

typedef struct {
    uint32_t          thread_context;  // The thread context for which this db was used.
    annotation_db_t  *pdb;
} annotation_db_ctx_t;

#define ANNOT_BUFF_COUNT 16
#define ANNOT_BUFF_SIZE  1024+1

typedef struct {
    uint32_t            BufferID;
    uint32_t            StartIndex;       // First Valid db entry
    uint32_t            EndIndex;         // Last Valid db entry
    uint32_t            Capacity;         // The Size of DB Buffer to For H/W Knowledge
    annotation_db_ctx_t Buffer[ANNOT_BUFF_SIZE];
} db_buffer_desc_t;

void mbb_annotation(annotation_db_t *pdb);

#endif
