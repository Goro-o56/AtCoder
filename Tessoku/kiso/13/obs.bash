#!/bin/bash

while true; do
  # 見つけた.cppファイルを格納する変数
  cpp_file=""

  # ディレクトリ内の.cppファイルを検索し、差分があるものを見つける
  for file in ./*.cpp; do
    # ファイルが存在しなければスキップ
    if [ ! -e "$file" ]; then
      continue
    fi

    # 差分があるかどうかを確認する
    if ! cmp --silent "$file" "$file.bak"; then
      cpp_file="$file"
      break
    fi
  done

  # 見つかった.cppファイルがあればg++でコンパイルする
  if [ -n "$cpp_file" ]; then
    g++ "$cpp_file" -o oj
  fi

  # 1秒ごとに差分を確認する
  sleep 1
done