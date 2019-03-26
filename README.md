Данный плагин позволяет запустить любой исполняющий файл в качестве 
фонового задания, с любым id и в любой очереди

#### Перед запуском 
```sh
yum install coremanager-devel
cd /usr/local/mgr5/src 
make -f isp.mk centos-prepare
git clone https://github.com/asvgit/longtask_qa.git
cd longtask_qa
make install
```

#### Создаём свой исполняющий файл
```sh
echo -en "\#\!/bin/bash\nsleep 9999999999" > /usr/local/mgr5/just_sleep.sh
chmod +x /usr/local/mgr5/just_sleep.sh
```

#### Запускаем задачу
```sh
/usr/local/mgr5/sbin/mgrctl -m billmgr longtask_qa binary=just_sleep.sh id=do_sleep
```
или
```sh
/usr/local/mgr5/sbin/mgrctl -m billmgr longtask_qa binary=just_sleep.sh id=do_sleep_1 queue=just_sleep_queue
/usr/local/mgr5/sbin/mgrctl -m billmgr longtask_qa binary=just_sleep.sh id=do_sleep_2 queue=just_sleep_queue
```
