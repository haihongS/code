Tera api
=======
## stratum <-> node
### getwork
/api/v2/GetWork
```
{
  "result":1,
  "data":[
    "a", // BlockNum
    "a", // MinerId
    "a", // SeqHash
    "a", // PrevHash
  ],
}
```
### submit
/api/v2/Submit
```
{
  "", // SeqHash
  "", // Hash
  "", // PowHash
  "", // Addrhash
}
```

## stratum <-> miner
### login
```
{
  id: 3,
  method: "login",
  params: ["accout.miner"],
}
```

### notify
```
{
  id: 3,
  method: "notify",
  result: [
    "11", // JobId
    "15", // RunRange
    "23", // StNonce
    "23", // BlockNum
    "33", // MinerId
    "f2", // PrevHash
    "3f", // SeqHash
  ],
}
```

### submit
```
{
  id: 4,
  method: "submit",
  result: [
    "11", // JobId
    "af", // BlockNum
    "ac", // SeqHash
    "ac", // Hash
    "ac", // PowHash
    "ac", // AddrHash
  ],
}

```
