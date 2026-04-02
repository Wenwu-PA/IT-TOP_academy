package com.example.todo_list
import com.example.todo_list.ui.components.TaskList
import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.padding
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.setValue
import androidx.compose.ui.Modifier
import androidx.compose.ui.res.stringResource
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import com.example.todo_list.ui.components.ClearButton
import com.example.todo_list.ui.components.TaskAdd

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            androidx.compose.material3.MaterialTheme {
                MainScreen()
            }
        }
    }
}

@Composable
fun MainScreen() {
    var taskText by remember { mutableStateOf("") }
    var tasks by remember { mutableStateOf(listOf<String>()) }

    Column(
        modifier = Modifier
            .fillMaxSize()
            .padding(
                top = 38.dp,
                start = 16.dp,
                end = 16.dp,
                bottom = 16.dp
            ),
        verticalArrangement = Arrangement.Top
    ) {

        Text(
            text = stringResource(R.string.main_text),
            fontSize = 24.sp
        )

        Spacer(modifier = Modifier.height(16.dp))

        TaskAdd(
            taskText = taskText,
            onTaskTextChange = { taskText = it },
            onAddTask = { newTask -> tasks = tasks + newTask }
        )

        Spacer(modifier = Modifier.height(16.dp))

        TaskList(
            tasks = tasks,
            modifier = Modifier.weight(1f)
        )

        Spacer(modifier = Modifier.height(16.dp))

        ClearButton(
            onClear = {
                taskText = ""
                tasks = emptyList()
            }
        )
    }
}