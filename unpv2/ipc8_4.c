#include "unpipc.h"
#include <pthread.h>

int pthread_rwlock_rdlock(pthread_rwlock_t *rw)
{
	int result;

	if (RW_MAGIC != rw->rw_magic)
	{
		return EINVAL;
	}
	if (0 !=(result = pthread_mutex_lock(&rw->rw_mutex)))
	{
		return result;
	}
	while(rw->rw_refcount <0 || rw->rw_nwaitwriters >0)
	{
		rw->rw_nwaitreaders++;
	}
	if (0==result)
	{
		rw->rw_refcount++;
	}
	pthread_mutex_unlock(&rw->rw_mutex);
	return result;
}