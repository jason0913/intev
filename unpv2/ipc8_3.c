#include "unpipc.h"
#include <pthread.h>

int pthread_rwlock_destroy(pthread_rwlock_t *rw)
{
	if (RW_MAGIC != rw->rw_magic)
	{
		return EINVAL;
	}
	if (0 != rw->rw_refcount || 0!= rw->nwaitreaders || 0 != rw->nwaitwriters)
	{
		return EBUSY;
	}
	pthread_mutext(&rw->rw_mutex);
	pthread_cond_destroy(&rw->rw_condreaders);
	pthread_cond_destroy(&rw->rw_condwriters);
	rw->rw_magic =0;

	return 0;
}