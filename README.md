# httpthreadpool

#### Description
http1.0 + threadpool


## 性能测试

短连接
>ab -n 100000 -c 100  http://127.0.0.1:8888/
```
Server Software:        httpd
Server Hostname:        127.0.0.1
Server Port:            8888

Document Path:          /
Document Length:        23715 bytes

Concurrency Level:      100
Time taken for tests:   3.450 seconds
Complete requests:      100000
Failed requests:        0
Total transferred:      2377400000 bytes
HTML transferred:       2371500000 bytes
Requests per second:    28983.56 [#/sec] (mean)
Time per request:       3.450 [ms] (mean)
Time per request:       0.035 [ms] (mean, across all concurrent requests)
Transfer rate:          672905.38 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        0    1   0.3      1       5
Processing:     1    2   0.5      2      15
Waiting:        0    1   0.4      1      13
Total:          1    3   0.5      3      16

Percentage of the requests served within a certain time (ms)
  50%      3
  66%      3
  75%      4
  80%      4
  90%      4
  95%      4
  98%      5
  99%      5
 100%     16 (longest request)


