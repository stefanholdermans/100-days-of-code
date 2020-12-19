import           Test.Tasty
import           Test.Tasty.HUnit

import           SpellPhoneNumber

main :: IO ()
main = defaultMain tests

tests :: TestTree
tests = testGroup
  "Letter combinations of a phone number"
  [ testCase "No digits"       testNoDigits
  , testCase "Single digit"    testSingleDigit
  , testCase "Two digits"      testTwoDigits
  , testCase "Spelling 'code'" testSpellingCode
  ]

testNoDigits :: Assertion
testNoDigits = spellPhoneNumber "" @?= []

testSingleDigit :: Assertion
testSingleDigit = spellPhoneNumber "2" @?= ["a", "b", "c"]

testTwoDigits :: Assertion
testTwoDigits =
  spellPhoneNumber "23"
    @?= ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]

testSpellingCode :: Assertion
testSpellingCode = "code" `elem` spellPhoneNumber "2633" @? "Not spelled"
