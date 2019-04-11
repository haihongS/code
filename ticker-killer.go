package main

import (
	"database/sql"
	"log"
	"os/exec"
	"time"

	_ "github.com/go-sql-driver/mysql"
)

var dbhost = "rms.com"
var dbusername = "ma"
var dbpassword = "macom"
var dbdatabase = "max"

func main() {
	for {
		time.Sleep(30 * time.Minute)
		sqlStr := "select count(id) as sum from block_history where coin_id = 1 and created >= UNIX_TIMESTAMP(NOW()) - 2 * 3600 order by id desc limit 500;"
		rows, err := queryDB(sqlStr)
		if err != nil {
			log.Fatal(err)
		}
		var lastSum int64
		for rows.Next() {
			var sum int64
			if err := rows.Scan(&sum); err != nil {
				log.Fatal(err)
			}
			lastSum = sum
			log.Println("block count", lastSum)
		}
		if err := rows.Err(); err != nil {
			log.Fatal(err)
		}

		if lastSum <= 0 {
			cmd := exec.Command("/bin/sh", "-c", "ps aux | grep -ie bytomd | awk '{print $2}' | xargs kill -9")
			if out, err := cmd.Output(); err != nil {
				log.Printf("err | %+v\n", err)
			} else {
				log.Printf("info | %+v\n", string(out))
			}
		}
	}
}

type DbWorker struct {
	Dsn string
}

func queryDB(sqlStr string, params ...[]interface{}) (*sql.Rows, error) {
	dbw := DbWorker{
		Dsn: dbusername + ":" + dbpassword + "@tcp(" + dbhost + ":3306)/" + dbdatabase,
	}
	db, err := sql.Open("mysql",
		dbw.Dsn)
	if err != nil {
		return nil, err
	}
	defer db.Close()
	return db.Query(sqlStr)
}
