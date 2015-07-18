#include "unpipc.h"
#include <pthread.h>

int pthread_rwlock_init(pthread_rwlock_t *rw,pthread_rwlockattr_t *attr)
{
	int result;

	if (NULL != attr)
	{
		return EINVAL;
	}
	if (0 != (result = pthread_mutex(&rw->rw_mutex,NULL)))
	{
		goto err1;
	}
	if (0 !=(result = pthread_cond_init(&rw->rw_condreaders,NULL)))
	{
		goto err2;
	}
	if (0 !=(result = pthread_cond_init(&rw->rw_condwriters,NULL)))
	{
		goto err3;
	}
	rw->rw_nwaitreaders = 0;
	rw->rw_nwaitsriters = 0;
	rw->rw_refcount =0;
	rw->rw_magic = RW_MAGIC;
	return 0;

	err3:
		pthread_cond_destroy(&rw->rw_condreaders);
	err2:
		pthread_mutex_destroy(&rw->rw_mutex);
	err1:
		return result;
}