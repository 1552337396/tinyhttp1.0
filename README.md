# httpthreadpool

#### Description
http1.0 + threadpool



#### ab 
Server Software:        httpd
Server Hostname:        127.0.0.1
Server Port:            8888

Document Path:          /
Document Length:        23715 bytes

Concurrency Level:      100
Time taken for tests:   3.576 seconds
Complete requests:      100000
Failed requests:        0
Total transferred:      2377400000 bytes
HTML transferred:       2371500000 bytes
Requests per second:    27965.97 [#/sec] (mean)
Time per request:       3.576 [ms] (mean)
Time per request:       0.036 [ms] (mean, across all concurrent requests)
Transfer rate:          649280.14 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        0    1   0.3      1       4
Processing:     0    2   0.5      2      11
Waiting:        0    1   0.4      1       9
Total:          2    4   0.5      3      13
ERROR: The median and mean for the total time are more than twice the standard
       deviation apart. These results are NOT reliable.

Percentage of the requests served within a certain time (ms)
  50%      3
  66%      4
  75%      4
  80%      4
  90%      4
  95%      4
  98%      5
  99%      5
 100%     13 (longest request)

Server Software:        httpd
Server Hostname:        127.0.0.1
Server Port:            8888

Document Path:          /
Document Length:        23715 bytes

Concurrency Level:      100
Time taken for tests:   3.407 seconds
Complete requests:      100000
Failed requests:        0
Total transferred:      2377400000 bytes
HTML transferred:       2371500000 bytes
Requests per second:    29349.07 [#/sec] (mean)
Time per request:       3.407 [ms] (mean)
Time per request:       0.034 [ms] (mean, across all concurrent requests)
Transfer rate:          681391.39 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        0    1   0.3      1       4
Processing:     0    2   0.5      2      11
Waiting:        0    1   0.4      1       9
Total:          0    3   0.4      3      13

Percentage of the requests served within a certain time (ms)
  50%      3
  66%      3
  75%      3
  80%      4
  90%      4
  95%      4
  98%      5
  99%      5
 100%     13 (longest request)


Server Software:        httpd
Server Hostname:        127.0.0.1
Server Port:            8888

Document Path:          /
Document Length:        23715 bytes

Concurrency Level:      100
Time taken for tests:   3.439 seconds
Complete requests:      100000
Failed requests:        0
Total transferred:      2377400000 bytes
HTML transferred:       2371500000 bytes
Requests per second:    29074.43 [#/sec] (mean)
Time per request:       3.439 [ms] (mean)
Time per request:       0.034 [ms] (mean, across all concurrent requests)
Transfer rate:          675015.20 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        0    1   0.3      1       3
Processing:     1    2   0.5      2      11
Waiting:        0    1   0.4      1       9
Total:          2    3   0.5      3      13

Percentage of the requests served within a certain time (ms)
  50%      3
  66%      3
  75%      4
  80%      4
  90%      4
  95%      4
  98%      5
  99%      5
 100%     13 (longest request)


