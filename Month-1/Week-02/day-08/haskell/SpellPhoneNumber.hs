module SpellPhoneNumber
  ( spellPhoneNumber
  ) where

import           Data.Maybe

spellPhoneNumber :: [Char] -> [String]
spellPhoneNumber []      = []
spellPhoneNumber [digit] = [ [letter] | letter <- letters digit ]
spellPhoneNumber (digit : digits) =
  [ letter : words | letter <- letters digit, words <- spellPhoneNumber digits ]

letters :: Char -> [Char]
letters '2' = "abc"
letters '3' = "def"
letters '4' = "ghi"
letters '5' = "jkl"
letters '6' = "mno"
letters '7' = "pqrs"
letters '8' = "tuv"
letters '9' = "wxyz"
