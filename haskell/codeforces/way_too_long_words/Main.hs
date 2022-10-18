module Main where

solve :: String -> String
solve i
  | length i <= 10 = i
  | otherwise = ([head i] ++ show (length i - 2) ++ [last i])

main :: IO ()
main = do
  w <- getLine
  words <- getContents
  putStrLn . unlines . map solve . lines $ words
